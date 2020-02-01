package com.example.websocketdemo.controller;

import com.example.websocketdemo.model.ChatMessage;

import java.util.ArrayList;

import org.springframework.messaging.handler.annotation.DestinationVariable;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.Payload;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.messaging.simp.SimpMessageHeaderAccessor;
import org.springframework.messaging.simp.annotation.SubscribeMapping;
import org.springframework.stereotype.Controller;

/**
 * Created by rajeevkumarsingh on 24/07/17.
 */
@Controller
public class ChatController {

    /*@MessageMapping("/chat.sendMessage")
    @SendTo("/topic/public")
    public ChatMessage sendMessage(@Payload ChatMessage chatMessage) {
        return chatMessage;
    }*/
	
	ArrayList<String> RoomList = new ArrayList();
	/*
	@SubscribeMapping("/topic/public/{roomId}")
	@SendTo("/topic/public/{roomId}")
	public void roomlist(@DestinationVariable String roomId) {
    	RoomList.add(roomId);
    	System.out.println(RoomList.get(0));
    }
    */
    @MessageMapping("/chat.sendMessage/{roomId}")
    @SendTo("/topic/public/{roomId}")
    public ChatMessage sendMessage(@Payload ChatMessage chatMessage) {
        return chatMessage;
    }
    
    @MessageMapping("/chat.addUser/{roomId}")
    @SendTo("/topic/public/{roomId}")
    public ChatMessage addUser(@Payload ChatMessage chatMessage,
                               SimpMessageHeaderAccessor headerAccessor) {
        // Add username in web socket session
    	
        headerAccessor.getSessionAttributes().put("username", chatMessage.getSender());

        return chatMessage;
    }
    /*
    @MessageMapping("/chat.addUser")
    @SendTo("/topic/public")
    public ChatMessage addUser(@Payload ChatMessage chatMessage,
                               SimpMessageHeaderAccessor headerAccessor) {
        // Add username in web socket session
        headerAccessor.getSessionAttributes().put("username", chatMessage.getSender());
        return chatMessage;
    }*/

}
