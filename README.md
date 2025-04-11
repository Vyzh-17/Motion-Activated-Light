# Motion-Activated-Light

🌟 Smart Motion-Activated Light with ESP32 + IoT Control 🌟

---

## 🧠 What You'll Build:
- A light that turns on when motion is detected.  
- Switch between Auto Mode (motion-controlled) and Manual Mode (controlled from your phone or PC).  
- Monitor and control it using Arduino IoT Cloud.

---

## 🧰 What You Need:

| Component                     | Quantity |
|------------------------------|----------|
| ESP32 Dev Board              | 1        |
| PIR Motion Sensor (HC-SR501) | 1        |
| LED (or Relay Module)        | 1        |
| 220Ω Resistor (for LED)      | 1        |
| Breadboard + Jumper Wires    | As needed|
| Arduino Account & Cloud      | 1        |

---

## 🔌 Wiring:

### PIR Sensor → ESP32
- VCC → 3.3V or 5V (preferable)  
- GND → GND  
- OUT → GPIO 13 (or any digital pin)

### LED (with resistor) → ESP32
- Anode (+) → GPIO 12 (or any digital pin) via 220Ω resistor  
- Cathode (–) → GND  

*If you're using a relay module, just replace the LED part with the relay IN pin connected to GPIO 12.*

---

## ☁️ Step 1: Setup Arduino IoT Cloud

1. Go to Arduino IoT Cloud  
2. Create a new Thing  
3. Add your ESP32 device  
4. Add these variables:  
   - `led` → type: Cloud Boolean, sync: Yes  
   - `autoModeCloud` → type: Cloud Boolean, sync: Yes  
5. Click on Sketch and it will auto-generate `thingProperties.h`  
6. In the generated sketch, paste the code:

---

## 📱 Step 2: Create Your Dashboard

1. Go to **Dashboards** in Arduino IoT Cloud  
2. Create a new dashboard and add:  
   - A Switch linked to `led`  
   - Another Switch linked to `autoModeCloud`  
3. Name them something clear like “Light Control” and “Auto Mode”

---

## 🚀 Step 3: Upload and Test

1. Plug in your ESP32  
2. Install drivers if needed  
3. Select the correct board and port in Arduino IDE  
4. Upload the sketch  
5. Open the serial monitor at 115200 baud to see messages  
6. Try switching between Auto Mode and Manual Mode from the dashboard

---

## ✅ How It Works

| Mode         | Behavior                                           |
|--------------|----------------------------------------------------|
| Auto Mode    | PIR sensor detects motion → LED turns on for 1 min |
| Manual Mode  | You control the LED directly via the dashboard     |

---

## 💡 Extras You Can Add Later

1. Notifications when motion is detected  
2. Real light bulb via relay  
3. Motion logs stored to the cloud

## Download driver - (CP210x_universal_windows_driver) connection of esp32.





  
