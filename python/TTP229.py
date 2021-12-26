from ctypes import *
import time

tp = CDLL('./TTP229.so')

while True:
    val = tp.TTP229_GetVal()
    time.sleep(0.5)
    if val & 1: 
        print("O")
    elif val & 2: 
        print("X")
    elif val & 4: 
        print("E")
    elif val & 8: 
        print("R")  
    elif val & 16: 
        print("Home")  
    elif val & 32: 
        print("+")
    elif val & 64: 
        print("-")
    elif val & 128: 
        print("L")
    elif val & 256: 
        print("Down")
    elif val & 512: 
        print("Right")
    elif val & 1024: 
        print("Up")
    elif val & 2048: 
        print("Left")
    elif val & 4096: 
        print("Power")
    elif val & 8192: 
        print("RP")
    elif val & 16384: 
        print("WS")
    elif val & 32768: 
        print("Y")
