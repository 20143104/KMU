package com.apress.spring.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import java.util.ArrayList;
import java.util.List;

import com.apress.spring.domain.Map;

public interface MapRepository extends JpaRepository<Map, Long> {
	List<Map> findByName(String name);
	int deleteById(Long id);
}
