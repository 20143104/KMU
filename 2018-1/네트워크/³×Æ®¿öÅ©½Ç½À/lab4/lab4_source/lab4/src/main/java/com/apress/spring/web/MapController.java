package com.apress.spring.web;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.transaction.annotation.Transactional;

import com.apress.spring.domain.Map;
import com.apress.spring.repository.MapRepository;



@Controller
public class MapController {

    @Autowired
    MapRepository repo_map;
    
    int count = 0;

    @RequestMapping(value = "/map", produces = { MediaType.APPLICATION_JSON_VALUE })
    public @ResponseBody List<Map> getMap() {
    	List<Map> x = repo_map.findAll();
        count++;
        if(count%2 == 0) {
        	//x.forEach((k)->{ k.setColor("#dddddd"); System.out.println("Item : " + k.getName() + " Count : " + k.getColor());});
        }
                	
        return x;
    }

    @RequestMapping(method = RequestMethod.GET, value = "/poll", produces = { MediaType.APPLICATION_JSON_VALUE })
    public @ResponseBody List<Map> getPoll() {
        return repo_map.findAll();
    }

	
//이 위치에 미완코드(데이터생성: POST) 완성할 것.            	
    @RequestMapping(method = RequestMethod.POST, value = "/poll", produces = { MediaType.APPLICATION_JSON_VALUE } )
    public @ResponseBody ResponseEntity<Map> postMap(@RequestBody final Map map){
    	
    	ResponseEntity<Map> L  = new ResponseEntity<Map>(map, HttpStatus.OK);
    	if(!repo_map.findByName(map.getName()).isEmpty())
    		return new ResponseEntity<Map>(HttpStatus.NOT_ACCEPTABLE);
    	Map m = new Map();
    	
    	
    	m.setName(map.getName());
    	m.setColor(map.getColor());
    	Map m2 = repo_map.save(m);
    	return new ResponseEntity<Map>(m2, HttpStatus.OK);
    }

	
//이 위치에 미완코드(데이터수정: PUT) 완성할 것. 
    
    @RequestMapping(method = RequestMethod.PUT, value = "/poll")
    public ResponseEntity<Map> update(@RequestBody Map map) {
        List <Map> m = repo_map.findByName(map.getName());
        
    	Map m2 = m.get(0);
    	
    	
    	m2.setName(map.getName());
    	m2.setColor(map.getColor());
    	repo_map.save(m2);
    	
    	return new ResponseEntity<Map>(m2, HttpStatus.OK);
    	
    	
    }
	
//이 위치에 미완코드(데이터삭제: DELETE) 완성할 것.            	
    @Transactional
    @RequestMapping( method = RequestMethod.DELETE, value = "/poll",produces = { MediaType.APPLICATION_JSON_VALUE } )
    public ResponseEntity<Void> deleteMap(@RequestBody Map map){
    	List <Map> m = repo_map.findByName(map.getName());
    	
    	if(m.size() == 0)
    			return new ResponseEntity<Void>(HttpStatus.NOT_FOUND);
    	m.get(0).setColor("#B9B9B9");
    	repo_map.deleteById(m.get(0).getId());
    	
        return new ResponseEntity<Void>(HttpStatus.OK);
 
    }
    
}
