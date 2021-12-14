#!/usr/bin/env python

import sys
import math
import socket
import ctypes
import struct
import turtle

IP, PORT = "192.168.43.237", 8080

class Kobuki(ctypes.Structure):
    _fields_ = [("x", ctypes.c_float),
                ("y", ctypes.c_float),
                ("angle", ctypes.c_float)]

class Obstacle(ctypes.Structure):
    _fields_ = [("x", ctypes.c_float),
                ("y", ctypes.c_float)]

class PacketData(ctypes.Union):
    _fields_ = [("kobuki", Kobuki),
                ("obstacle", Obstacle)]

class Packet(ctypes.Structure):
    _fields_ = [("packet_type", ctypes.c_int),
                ("packet_data", PacketData)]
    KOBUKI = 0
    OBSTACLE = 1

kobuki_turtle = turtle.Turtle()
kobuki_turtle.shape("turtle")
kobuki_turtle.penup()
kobuki_turtle.speed(0)
kobuki_turtle.seth(90)
kobuki_turtle.speed(1)
obstacle_turtle = turtle.Turtle()
obstacle_turtle.hideturtle()
obstacle_turtle.penup()
obstacle_turtle.speed(0)
turtle.setup(600, 600)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((IP, PORT))
    s.listen()
    print("Listening for connections...")
    conn, addr = s.accept()
    with conn:
        print("Connected with", addr)
        while True:
            data = conn.recv(ctypes.sizeof(Packet))
            if len(data) == 0:
                print("Disconnected")
                break
            packet = Packet()
            ctypes.memmove(ctypes.pointer(packet), data, ctypes.sizeof(packet))
            if packet.packet_type == Packet.KOBUKI:
                kobuki_turtle.seth(180 + packet.packet_data.kobuki.angle / math.pi * 180)
                kobuki_turtle.goto(-120 * packet.packet_data.kobuki.x, -120 * packet.packet_data.kobuki.y)
            elif packet.packet_type == Packet.OBSTACLE:
                obstacle_turtle.goto(-120 * packet.packet_data.obstacle.x, -120 * packet.packet_data.obstacle.y)
                obstacle_turtle.dot(48, "blue")
            # print(packet.packet_type)
            # print(packet.packet_data.obstacle.x)
            # print(packet.packet_data.obstacle.y)
            # print(packet.packet_data.kobuki.angle)
    while True:
        pass
