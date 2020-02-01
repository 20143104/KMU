package com.cclab.web.server;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import com.cclab.web.server.domain.Member;
import com.cclab.web.server.repository.MemberRepository;

import com.cclab.web.server.domain.Login;
import com.cclab.web.server.repository.LoginRepository;


@SpringBootApplication
public class HTTP_Server {
	
    @Bean
    InitializingBean saveData(MemberRepository repo,LoginRepository repo2) {
        return () -> {
            repo.save(new Member("홍길동", 86, "960330-1306548"));
            repo.save(new Member("오영희", 48, "030702-4138926"));
            repo.save(new Member("김철수", 63, "050810-3306548"));
            repo.save(new Member("윤명숙", 43, "030302-2306548"));
            repo.save(new Member("이하나", 52, "980330-2306548"));
            repo2.save(new Login("abc", "123", "naver",1));
            repo2.save(new Login("cdf", "456", "gmail",2));
            repo2.save(new Login("zxc", "456", "gmail",5));
        };
    }
    /*
    @Bean
    InitializingBean saveData(LoginRepository repo2) {
        return () -> {
            repo2.save(new Login("홍길동", "86", "960330-1306548",1));
            repo2.save(new Login("오영희", "48", "030702-4138926",2));
            repo2.save(new Login("김철수", "63", "050810-3306548",3));
            repo2.save(new Login("윤명숙", "43", "030302-2306548",4));
            repo2.save(new Login("이하나", "52", "980330-2306548",5));
        };
    }*/
    
    
    
    
	public static void main(String[] args) {
		SpringApplication.run(HTTP_Server.class, args);
	}
}
