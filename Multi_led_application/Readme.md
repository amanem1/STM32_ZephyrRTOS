# Multi-LED Blinking with Zephyr on STM32L496  

## Overview  
This project demonstrates a **multi-LED blinking application** using Zephyr RTOS on the **STM32L496** board. The code efficiently toggles multiple LEDs simultaneously without using **threads**, making it a lightweight and optimized solution for resource-constrained embedded systems.  

## Project Features  
- Uses **Zephyr's GPIO API** to control multiple LEDs.  
- Blinks three LEDs (`led0`, `led1`, and `led2`) in a single loop.  
- Avoids unnecessary overhead by **not using threads**.  
- Optimized **loop-based LED control**, making it easy to scale for more LEDs.  

## Why This is an Optimized Approach?  

### 1. Using Arrays for LED Configuration  
Instead of handling each LED separately with redundant function calls, we store all LED configurations in an **array** and use a loop for:  
- **Initialization**  
- **Pin configuration**  
- **Toggling LEDs**  

This removes repetitive code and makes it **easier to scale** if more LEDs are added.  

### 2. No Threads = Lower Overhead  
Typical **RTOS-based** implementations use **separate threads** (tasks) for each LED. This approach:  
- Requires context switching, which **adds CPU overhead**.  
- Uses more **RAM** for stack allocation.  
- Increases power consumption **due to more active CPU cycles**.  

By running everything inside the **main loop**, we avoid these inefficiencies while still achieving simultaneous LED toggling.  

### 3. Synchronized LED Toggling  
With threads, LEDs might toggle at slightly different times due to **task scheduling delays**. Here, all LEDs toggle in the **same loop iteration**, ensuring precise **synchronization**.  

## Board Used: STM32L496  

### Prerequisites  
- Zephyr RTOS installed  
- STM32L496 board  
- A connected debugger (ST-Link or OpenOCD)  

### How to Build & Flash  

#### Clone the Repository  
```sh
git clone https://github.com/amanem1/STM32_ZephyrRTOS.git
cd STM32_ZephyrRTOS/Multi_led_application
west build -b nucleo_l496zg
