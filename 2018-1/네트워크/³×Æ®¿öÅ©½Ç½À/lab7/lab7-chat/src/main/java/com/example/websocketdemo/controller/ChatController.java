package com.example.websocketdemo.controller;

import com.example.websocketdemo.model.ChatMessage;

import java.util.ArrayList;
import java.util.List;

import org.springframework.http.MediaType;
import org.springframework.messaging.handler.annotation.DestinationVariable;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.Payload;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.messaging.simp.SimpMessageHeaderAccessor;
import org.springframework.messaging.simp.annotation.SubscribeMapping;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

/**
 * Created by rajeevkumarsingh on 24/07/17.
 */
@Controller
public class ChatController {
	/*
    @MessageMapping("/chat.sendMessage")
    @SendTo("/topic/public")
    public ChatMessage sendMessage(@Payload ChatMessage chatMessage) {
        return chatMessage;
    }*/
    ArrayList<String> RoomList = new ArrayList();
    String result;
    
    @RequestMapping(method = RequestMethod.GET, value = "/roomlist", produces = { MediaType.APPLICATION_JSON_VALUE })
    public @ResponseBody String getroom() {
    	result="";
    	ArrayList<String> resultlist = new ArrayList();
    	
    	for(int i=0; i<RoomList.size(); i++) {
    		if(!resultlist.contains(RoomList.get(i)))
    			resultlist.add(RoomList.get(i));
    	}
    	
    	for(int i=0; i<resultlist.size(); i++) {
    		result = result + resultlist.get(i) + ',';
    	}
    	return result;
    }
    
    @SubscribeMapping("/topic/public/{roomId}")
    public void roomlist(@DestinationVariable String roomId) {
    	RoomList.add(roomId);
    	System.out.println(RoomList.size());
    }
   
    @MessageMapping("/chat.sendMessage/{roomId}")
    @SendTo("/topic/public/{roomId}")
    public ChatMessage sendMessage(@Payload ChatMessage chatMessage) {
        return chatMessage;
    }

    @MessageMapping("/chat.addUser/{roomId}")
    @SendTo("/topic/public/{roomId}")
    public ChatMessage addUser(@Payload ChatMessage chatMessage,
                               SimpMessageHeaderAccessor headerAccessor,
                               @DestinationVariable String roomId) {
        // Add username in web socket session
        headerAccessor.getSessionAttributes().put("username", chatMessage.getSender());
        headerAccessor.getSessionAttributes().put("roomId", roomId);
        return chatMessage;
    }
    /*@MessageMapping("/chat.addUser")
    @SendTo("/topic/public")
    public ChatMessage addUser(@Payload ChatMessage chatMessage,
                               SimpMessageHeaderAccessor headerAccessor) {
        // Add username in web socket session
        headerAccessor.getSessionAttributes().put("username", chatMessage.getSender());
        return chatMessage;
    }*/
    

}
