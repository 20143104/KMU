package com.cclab.website.interceptor;

import java.util.concurrent.atomic.AtomicInteger;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.handler.HandlerInterceptorAdapter;

import java.util.Timer;
import java.util.TimerTask;

@Component
public class MetricInterceptor extends HandlerInterceptorAdapter {
	private AtomicInteger counter = new AtomicInteger(0);
	private boolean setup = false;

	@Override
    public boolean preHandle(HttpServletRequest request, 
            HttpServletResponse response, Object handler) throws Exception {
		
		    if(!setup) {		    	
		    	TimerTask task = new TimerTask() {
		    		@Override
		    		public void run() {
		    			// task to run goes here
//		    			System.out.println("Hello !!!");
		    			counter.set(0);
		    		}
		    	};
		    	Timer timer = new Timer();
		    	long delay = 0;
		    	long intevalPeriod = 10 * 1000;
		    	// schedules the task to be run in an interval
		    	timer.scheduleAtFixedRate(task, delay, intevalPeriod);
		    	setup = true;
		    }
		    
            String x = request.getMethod();
            String p = request.getRequestURI();
            
            if(x.equalsIgnoreCase("GET") && p.startsWith("/metric"))
            {
                request.setAttribute("VisitCount", counter.get());
            	
            }
            else
            {
            	System.out.println(request.getRequestURL() + " : " + request.getMethod());
                request.setAttribute("VisitCount", counter.incrementAndGet());
                
 // (4) 구현 위치 #(1/2)
                
            }

            return true;
    }
	
}