package com.example.websocketdemo.controller;

import com.example.websocketdemo.model.ServiceMessage;
import com.example.websocketdemo.model.ServiceMessage.MessageType;
import com.example.websocketdemo.model.ChatMessage;
import com.example.websocketdemo.model.DrawMessage;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.Payload;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.messaging.simp.SimpMessageHeaderAccessor;
import org.springframework.stereotype.Controller;

@Controller
public class ChatController {

	@MessageMapping("/chat.sendMessage")
    @SendTo("/topic/public")
    public ServiceMessage sendMessage(@Payload ChatMessage chatMessage) {
    	ServiceMessage sm = new ServiceMessage();
    	sm.setType(ServiceMessage.MessageType.CHAT);
    	sm.setChat(chatMessage);
        return sm;
    }
	
	@MessageMapping("/chat.drawMessage")
    @SendTo("/topic/public")
    public ServiceMessage sendLineMessage(@Payload DrawMessage drawMessage) {
    	ServiceMessage sm = new ServiceMessage();
    	sm.setType(ServiceMessage.MessageType.DRAW);
    	sm.setdraw(drawMessage);
        return sm;
    }
	
    @MessageMapping("/chat.addUser")
    @SendTo("/topic/public")
    public ServiceMessage addUser(@Payload ChatMessage chatMessage,
                               SimpMessageHeaderAccessor headerAccessor) {
        // Add username in web socket session
        headerAccessor.getSessionAttributes().put("username", chatMessage.getSender());
    	ServiceMessage sm = new ServiceMessage();
    	sm.setType(ServiceMessage.MessageType.CHAT);
    	sm.setChat(chatMessage);
        return sm;
    }

}
