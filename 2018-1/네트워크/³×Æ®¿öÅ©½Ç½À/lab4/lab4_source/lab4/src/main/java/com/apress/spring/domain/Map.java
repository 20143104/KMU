package com.apress.spring.domain;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Transient;

@Entity
public class Map {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String name;
    private String color;

    public Map(String name, String color)
            throws ParseException {
        this.name = name;
        this.color = color;
    }

    public Map(Map m) {
    	this.id = m.id;
    	this.name = m.name;
    	this.color = m.color;
    }
    
    public Map() {
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String toString() {
        StringBuilder value = new StringBuilder("MapEntry(");
        value.append("Id: ");
        value.append(id);
        value.append(",이름: ");
        value.append(name);
        value.append(",색깔: ");
        value.append(color);
        value.append(")");
        return value.toString();
    }
}
