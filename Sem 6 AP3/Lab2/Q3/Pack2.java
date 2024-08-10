package com.jiet;

import com.juet.Pack1;

public class Pack2 extends Pack1{
    protected void display(){
        System.out.println("Inside Package com.jiet > Pack2 > DisplayMethod");
    }
    
    public static void main (String[] args) {
        Pack1 p1 = new Pack1();
        p1.display();
    }
}