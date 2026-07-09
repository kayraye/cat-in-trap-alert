// ESP32 - HardwareSerial for LoRa (UART2)
HardwareSerial lora(2);  // UART2

void setup() {
  Serial.begin(115200);

  // Start LoRa UART
  // RX = 16, TX = 17 for DOIT DevKit V1
  lora.begin(115200, SERIAL_8N1, 14, 27);

  Serial.println("ESP32 Ready. Type text to send over LoRa:");
}

void loop() {

  // ---- Read text from USB Serial ----
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    text.trim();

    if (text.length() > 0) {
      String cmd = text + "\r\n";

      lora.print(cmd);

      Serial.print("TX → ");
      Serial.println(cmd);
    }
  }

  // ---- Read responses from LoRa ---- i made some edits here
  while (lora.available()) {
    Serial.write(lora.read());
  }
  
  delay(10);
}
