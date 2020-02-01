package com.cclab.ssh;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.ChannelSftp;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;

import java.util.Map;
import java.util.HashMap;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.client.RestTemplate;

@SpringBootApplication
public class LabSshApplication {

	@Autowired
 	private static RestTemplate restTemplate;
	
	public static void main(String[] args) {
		SpringApplication.run(LabSshApplication.class, args);
	}
	
    @Bean
    CommandLineRunner init(RestTemplate restTemplate) {
    	return (args) -> {
	
	    ArrayList<MyThread> threads = new ArrayList<MyThread>();
	    int port = 8090;
	    int cnt = 0;
	    int acc = 0;
	    int vc, vc2;
	    
		while(true) {
			
		try {
			
		Map<String, Integer> metric = restTemplate.getForObject("http://"+"localhost:8080"+"/metric", Map.class);
		vc = metric.get("VisitCount");
		vc2 = metric.get("VisitCount2");
		System.out.println("VisitCount: " + vc);
		System.out.println("VisitCount2: " + vc2);
		if((vc + vc2) >= 4 && cnt <= 2) {
			System.out.println("New Web Server starts at port = " + (port+cnt));
			String x = "start /min /B java -jar --add-modules java.xml.bind lab3-0.0.1-SNAPSHOT.jar --server.port=" +(port+cnt);
			MyThread th1 = new MyThread("a",x);
			th1.start();
			threads.add(th1);
			cnt++;
			
			Thread.sleep(10000);
			
		}
		
		else {
				if(vc + vc2 <= 1) acc++;
				else acc = 0;
			
				if(acc >= 10) {
					acc = 0;
					if(threads.size()>0) {
						System.out.println("Web Server Service stops at port=" + (port+threads.size()-1));
						MyThread th = threads.remove(threads.size()-1);
						th.stop();
						cnt--;
						Thread.sleep(10000);
				}
			}
		}
		
		} catch (InterruptedException e) {}
		
		}
		
    };

    }

}
    

class MyThread implements Runnable {

	boolean suspended = false;

	boolean stopped = false;

	String command;

	Thread th;

    Channel channel = null;
    Session session = null;
    
	MyThread(String name, String command) {
		this.command = command;

		th = new Thread(this, name); // Thread(Runnable r, String name)

	}



	public void run() {

        String username = "csh40";
        String host = "localhost";
        int port = 22; // (SSH서버포트번호)
        String password = "whtmdgus120!";
        
     
        // 2. 세션 객체를 생성한다 (사용자 이름, 접속할 호스트, 포트를 인자로 준다.)
        try {
            // 1. JSch 객체를 생성한다.
            JSch jsch = new JSch();
            session = jsch.getSession(username, host, port);
         
            // 3. 패스워드를 설정한다.
            session.setPassword(password);
         
            // 4. 세션과 관련된 정보를 설정한다.
            java.util.Properties config = new java.util.Properties();
            // 4-1. 호스트 정보를 검사하지 않는다.
            config.put("StrictHostKeyChecking", "no");
            session.setConfig(config);
         
            // 5. 접속한다.
            session.connect();
         
            // 6. exec 채널을 연다.
            channel = session.openChannel("exec");
            BufferedReader in=new BufferedReader(new InputStreamReader(channel.getInputStream()));
         
            // 8. SSH/Exec채널객체로 캐스팅한다
            ChannelExec channelExec = (ChannelExec) channel;
         
            System.out.println("==> Connecting to" + host);
           
            channelExec.setCommand(command);
            channelExec.connect();
            String msg=null;
            while((msg=in.readLine())!=null){
              System.out.println(msg);
            }
            
            System.out.println("==> Connected to" + host + "; (command)= " + command);

            while(true) {}
                  
        } catch (JSchException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (channel != null) {
                channel.disconnect();
            }
            if (session != null) {
                session.disconnect();
            }
        }

	}



	public void suspend() {

		suspended = true;

		th.interrupt();

// interrupt(): 특정 객체를 멈추고자 할때 사용, 쓰레드의 권한 중지

		System.out.println("interrupt() in suspend()");

	}



	public void resume() {

		suspended = false;

	}



	public void stop() {

		stopped = true;

        channel.disconnect();
        session.disconnect();

//        th.interrupt();
//        th.stop();

		System.out.println("interrupt() in stop()");

	}



	public void start() {

		th.start();

	}

}

@Configuration
class AppConfiguration {

//    @LoadBalanced
    @Bean
    RestTemplate restTemplate() {
        return new RestTemplate();
    }
}
