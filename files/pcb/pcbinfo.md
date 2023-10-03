# Printed Circuit Board Designing
Process of desinging the PCB for the system
> [!WARNING]
> PCB has not been produced or tested. Use at your own risk.

## Fritzing Schematic

<div align=center>
  <img src="/assets/images/DataCollectionPrototype3.png" width="700" alt="PCB design of Data Collection Prototype"/>
  <br>
  Copper Layer SVGs Compiled Into One Image
</div>

<br>

## Process

This PCB was designed with a few key goals in mind.

- To avoid having an impact of the data results the device placement needs to be carefully chosen. With the 76mm x 23mm compact and low profile design we can position the device in an optimal location to minimize impact on the abilities of the athlete during data recording.
- Through the use of custom footprints, the sensor can be attached directly to the board or through the use of wires to allow for the most flexibility when recording data.
- The Adafruit micro SD card breakout board components were moved directly onto the main PCB allowing an even more compact design and more support for the micro SD card slot.

<div align=center>
  <img src="/assets/images/DataCollectionPrototype_footprints.PNG" width="700" alt="IMG3"/>
  <br>
  KiCad PCB Designer Layout of Circuit Board
</div>
<div align=center>
  <img src="/assets/images/DataCollectionPrototype1.png" width="700" alt="IMG1"/>
  <br>
  KiCad Render of Circuit Board Top
</div>
<div align=center>
  <img src="/assets/images/DataCollectionPrototype2.png" width="700" alt="IMG2"/>
  <br>
  KiCad Render of Circuit Board Bottom
</div>
