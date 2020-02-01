package com.cclab.web.server.domain;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Transient;

@Entity
public class Member {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String name;
    private double weight;
    private String rrid;
    private String gender;

    public Member(String name, double weight, String rrid)
            throws ParseException {
        this.name = name;
        this.weight = weight;
        this.rrid = rrid;
        char ch = rrid.charAt(7);
        this.gender = (ch == '1' || ch == '3')  ? "남자" : "여자";
    }

    public Member(Member m) {
    	this.id = m.id;
        this.name = m.name;
        this.weight = m.weight;
        this.rrid = m.rrid;
        this.gender = m.gender;
    }

    public Member() {
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

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public String getRrid() {
        return rrid;
    }

    public void setRrid(String rrid) {
        this.rrid = rrid;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String toString() {
        StringBuilder value = new StringBuilder("MapEntry(");
        value.append("Id: ");
        value.append(id);
        value.append(", 이름: ");
        value.append(name);
        value.append(", 몸무게: ");
        value.append(weight);
        value.append(", 주민번호: ");
        value.append(rrid);
        if(gender != null) {
        	value.append(", 성별: ");
        	value.append(gender);
        }
        value.append(")");
        return value.toString();
    }
}
