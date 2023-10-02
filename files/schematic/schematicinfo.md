# Schematic Designing
Process of desinging the schematic for the system
> [!NOTE]
> Schematics are based off of physical prototype and have not been verified

## Fritzing Schematic

<div align=center>
  <img src="/assets/images/DataCollectionPrototype_schem.png" width="700" alt="Schematic of Data Collection Prototype"/>
  <br>
  Schematic of Prototype (Created in Fritzing)
</div>

<br>

<details>
<summary><b>Symbols used in Schematic</b></summary>
  
- Adafruit Metro Mini (Adafruit #2590)
- Adafruit AM2320 Temperature and Humidity Sensor (Adafruit #3721)
- Adafruit Micro SD Card Breakout Board (Adafruit #254)
- R4 10kΩ THT Resistor
- R5 10kΩ THT Resistor

**Labels**
- 5V  - Power in
- GND - Signal/power ground
- VDD - Power in, can be 3-5VDC (5v in this device)
- SDA - I2C data in/out, requires a pullup of 2-10K to VDD
- SCL - I2C clock in, requires a pullup of 2-10K to VDD
- CS  - Chip Select
- DI  - Direct Input
- DO  - Direct Output
- CLK - Clock

</details>
