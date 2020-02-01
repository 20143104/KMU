package com.apress.spring;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import com.apress.spring.domain.Map;
import com.apress.spring.repository.MapRepository;

@SpringBootApplication
public class MapApplication {

    @Bean
    InitializingBean saveData(MapRepository repo_map) {
        return () -> {
            repo_map.save(new Map("세종특별자치시", "#00ff00"));
        	repo_map.save(new Map("원주시", "#ff0000"));
        	repo_map.save(new Map("제주시", "#00ffff"));
        	repo_map.save(new Map("서귀포시", "#0000ff"));
        	repo_map.save(new Map("강동구", "#0000ff"));
        };
    }

    @Bean
    CommandLineRunner init(MapRepository repo) {
        return args -> {
            System.out.println("---------------------------------");
            repo.findAll().forEach(System.out::println);
            System.out.println("---------------------------------");
        };
    }

    public static void main(String[] args) {
        SpringApplication.run(MapApplication.class, args);
    }
}
