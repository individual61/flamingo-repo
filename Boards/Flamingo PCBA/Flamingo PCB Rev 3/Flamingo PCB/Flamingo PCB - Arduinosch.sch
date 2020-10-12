EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:C C201
U 1 1 5F78D849
P 1250 1550
F 0 "C201" H 1365 1596 50  0000 L CNN
F 1 "C" H 1365 1505 50  0000 L CNN
F 2 "" H 1288 1400 50  0001 C CNN
F 3 "~" H 1250 1550 50  0001 C CNN
F 4 "-" H 1250 1550 50  0001 C CNN "Description"
F 5 "MFR P/N" H 1250 1550 50  0001 C CNN "MFR P/N"
F 6 "-" H 1250 1550 50  0001 C CNN "Manufacturer"
F 7 "-" H 1250 1550 50  0001 C CNN "Website"
F 8 "-" H 1250 1550 50  0001 C CNN "Digi-Key_PN"
	1    1250 1550
	1    0    0    -1  
$EndComp
Text Notes 700  1150 0    50   ~ 0
C0G dielectric, ultra stable cerapic cap, 12 - 22 pF, qty 2, both the same
$Comp
L Device:C C204
U 1 1 5F78FF1B
P 1750 1550
F 0 "C204" H 1865 1596 50  0000 L CNN
F 1 "C" H 1865 1505 50  0000 L CNN
F 2 "" H 1788 1400 50  0001 C CNN
F 3 "~" H 1750 1550 50  0001 C CNN
F 4 "-" H 1750 1550 50  0001 C CNN "Description"
F 5 "MFR P/N" H 1750 1550 50  0001 C CNN "MFR P/N"
F 6 "-" H 1750 1550 50  0001 C CNN "Manufacturer"
F 7 "-" H 1750 1550 50  0001 C CNN "Website"
F 8 "-" H 1750 1550 50  0001 C CNN "Digi-Key_PN"
	1    1750 1550
	1    0    0    -1  
$EndComp
Text Notes 700  2050 0    50   ~ 0
100 nF X7R ceramic capacitors rated for at least 16 volts. \ndecoupling capacitor for each VCC pin.
$Comp
L Device:C C202
U 1 1 5F79041B
P 1300 2650
F 0 "C202" H 1415 2696 50  0000 L CNN
F 1 "C" H 1415 2605 50  0000 L CNN
F 2 "" H 1338 2500 50  0001 C CNN
F 3 "~" H 1300 2650 50  0001 C CNN
F 4 "-" H 1300 2650 50  0001 C CNN "Description"
F 5 "MFR P/N" H 1300 2650 50  0001 C CNN "MFR P/N"
F 6 "-" H 1300 2650 50  0001 C CNN "Manufacturer"
F 7 "-" H 1300 2650 50  0001 C CNN "Website"
F 8 "-" H 1300 2650 50  0001 C CNN "Digi-Key_PN"
	1    1300 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C203
U 1 1 5F790A46
P 1700 2650
F 0 "C203" H 1815 2696 50  0000 L CNN
F 1 "C" H 1815 2605 50  0000 L CNN
F 2 "" H 1738 2500 50  0001 C CNN
F 3 "~" H 1700 2650 50  0001 C CNN
F 4 "-" H 1700 2650 50  0001 C CNN "Description"
F 5 "MFR P/N" H 1700 2650 50  0001 C CNN "MFR P/N"
F 6 "-" H 1700 2650 50  0001 C CNN "Manufacturer"
F 7 "-" H 1700 2650 50  0001 C CNN "Website"
F 8 "-" H 1700 2650 50  0001 C CNN "Digi-Key_PN"
	1    1700 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C205
U 1 1 5F790FAC
P 2150 2650
F 0 "C205" H 2265 2696 50  0000 L CNN
F 1 "C" H 2265 2605 50  0000 L CNN
F 2 "" H 2188 2500 50  0001 C CNN
F 3 "~" H 2150 2650 50  0001 C CNN
F 4 "-" H 2150 2650 50  0001 C CNN "Description"
F 5 "MFR P/N" H 2150 2650 50  0001 C CNN "MFR P/N"
F 6 "-" H 2150 2650 50  0001 C CNN "Manufacturer"
F 7 "-" H 2150 2650 50  0001 C CNN "Website"
F 8 "-" H 2150 2650 50  0001 C CNN "Digi-Key_PN"
	1    2150 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C206
U 1 1 5F79155A
P 2550 2650
F 0 "C206" H 2665 2696 50  0000 L CNN
F 1 "C" H 2665 2605 50  0000 L CNN
F 2 "" H 2588 2500 50  0001 C CNN
F 3 "~" H 2550 2650 50  0001 C CNN
F 4 "-" H 2550 2650 50  0001 C CNN "Description"
F 5 "MFR P/N" H 2550 2650 50  0001 C CNN "MFR P/N"
F 6 "-" H 2550 2650 50  0001 C CNN "Manufacturer"
F 7 "-" H 2550 2650 50  0001 C CNN "Website"
F 8 "-" H 2550 2650 50  0001 C CNN "Digi-Key_PN"
	1    2550 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2500 1300 2350
Wire Wire Line
	1300 2350 1700 2350
Wire Wire Line
	2550 2350 2550 2500
Wire Wire Line
	2150 2500 2150 2350
Connection ~ 2150 2350
Wire Wire Line
	2150 2350 2550 2350
Wire Wire Line
	1700 2500 1700 2350
Connection ~ 1700 2350
Wire Wire Line
	1700 2350 2150 2350
Wire Wire Line
	1300 2800 1300 3000
Wire Wire Line
	2550 3000 2550 2800
Wire Wire Line
	1300 3000 1700 3000
Wire Wire Line
	2150 2800 2150 3000
Connection ~ 2150 3000
Wire Wire Line
	2150 3000 2550 3000
Wire Wire Line
	1700 2800 1700 3000
Connection ~ 1700 3000
Wire Wire Line
	1700 3000 2150 3000
Text Notes -3700 950  0    50   ~ 0
ATmega328-AU Surface mount (Low/Thin Profile Plastic Quad Flat Package)\nATmega328-AUR Same thing on a tape reel for automatic pick and place machines\n\nATmega328-MU Surface mount (very thin fine pitch quad flat, no lead package)\nATmega328-MUR Same thing on a tape reel for automatic pick and place machines\n\nATmega328-PU  28-pin DIP\n\n(Same also for ATmega328P)
Text Notes -3750 1900 0    50   ~ 0
The -PU and -AU suffixes indicate packaging and temperature range\n\n -P indicates a DIP, \n-A indicates a TQFP, and \n-M is a QFN.  \n\nU means "industrial" temperature range.
$Comp
L MyConnectors:FTDI_Header J201
U 1 1 5F844162
P 1850 5400
F 0 "J201" H 1850 5750 50  0000 C TNN
F 1 "FTDI_Header" H 1850 5000 50  0000 C CNN
F 2 "" H 1850 5400 50  0001 C CNN
F 3 "~" H 1850 5400 50  0001 C CNN
F 4 "-" H 1850 5400 50  0001 C CNN "MPN"
F 5 "-" H 1850 5400 50  0001 C CNN "Digi-Key_PN"
F 6 "-" H 1850 5400 50  0001 C CNN "Website"
F 7 "-" H 1850 5400 50  0001 C CNN "Description"
F 8 "-" H 1850 5400 50  0001 C CNN "Manufacturer"
	1    1850 5400
	-1   0    0    1   
$EndComp
$Comp
L MyICs:ATMEGA328P-AU U201
U 1 1 5F846AEA
P 10700 4500
F 0 "U201" H 9400 6050 60  0000 L CNN
F 1 "ATMEGA328P-AU" V 10900 4550 60  0000 C CNN
F 2 "digikey-footprints:TQFP-32_7x7mm" H 11250 4700 60  0001 L CNN
F 3 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 11250 4800 60  0001 L CNN
F 4 "ATMEGA328P-AU-ND" H 11250 4900 60  0001 L CNN "Digi-Key_PN"
F 5 "ATMEGA328P-AU" H 11250 5000 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 11250 5100 60  0001 L CNN "Category"
F 7 "Embedded - Microcontrollers" H 11250 5200 60  0001 L CNN "Family"
F 8 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 11250 5300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/microchip-technology/ATMEGA328P-AU/ATMEGA328P-AU-ND/1832260" H 11250 5400 60  0001 L CNN "DK_Detail_Page"
F 10 "IC MCU 8BIT 32KB FLASH 32TQFP" H 11250 5500 60  0001 L CNN "Description"
F 11 "Microchip Technology" H 11250 5600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 11250 5700 60  0001 L CNN "Status"
F 13 "Derived from DK symbol" H 11700 5950 50  0001 C CNN "Attribution"
	1    10700 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5400 3350 5400
Text Label 3350 5400 0    50   ~ 0
V_BUS
Wire Wire Line
	2050 5500 2150 5500
Wire Wire Line
	2050 5600 2150 5600
Wire Wire Line
	2150 5500 2150 5600
$Comp
L power:GND #PWR0201
U 1 1 5F84DF41
P 2150 5600
F 0 "#PWR0201" H 2150 5350 50  0001 C CNN
F 1 "GND" H 2150 5450 50  0000 C CNN
F 2 "" H 2150 5600 50  0001 C CNN
F 3 "" H 2150 5600 50  0001 C CNN
	1    2150 5600
	1    0    0    -1  
$EndComp
Connection ~ 2150 5600
$Comp
L power:+5V #PWR0203
U 1 1 5F84F6BB
P 4800 4700
F 0 "#PWR0203" H 4800 4550 50  0001 C CNN
F 1 "+5V" H 4800 4840 50  0000 C CNN
F 2 "" H 4800 4700 50  0001 C CNN
F 3 "" H 4800 4700 50  0001 C CNN
	1    4800 4700
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R?
U 1 1 5F8530A4
P 4800 4850
AR Path="/5F780D75/5F8530A4" Ref="R?"  Part="1" 
AR Path="/5F780A01/5F8530A4" Ref="R201"  Part="1" 
F 0 "R201" H 4881 4962 50  0000 L CNN
F 1 "10k" H 4881 4871 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4855 4800 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 4800 4850 50  0001 C CNN
F 4 "0603" H 4881 4780 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 4881 4689 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 4800 4850 50  0001 C CNN "Description"
F 7 "Yageo" H 4800 4850 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 4800 4850 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 4800 4850 50  0001 C CNN "Digi-Key_PN"
	1    4800 4850
	1    0    0    -1  
$EndComp
$Comp
L MyCapacitors:C_Small_horizontal C207
U 1 1 5F85B8E0
P 4400 5050
F 0 "C207" H 4200 5550 50  0000 L CNN
F 1 "0.1uF" H 4200 5450 50  0000 L CNN
F 2 "" V 4275 5000 50  0001 L CNN
F 3 "" H 4200 5525 50  0001 L CNN
F 4 "XXXX" H 4200 5250 50  0000 L CNN "Package Size"
F 5 "Voltage" H 4200 5350 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 4200 5150 50  0000 L CNN "MPN"
F 7 "-" H 4200 5350 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 4200 5350 50  0001 L CNN "Prefix"
F 9 "-" H 4200 5350 50  0001 L CNN "Website"
F 10 "-" H 4200 5350 50  0001 L CNN "Description"
F 11 "-" H 4200 5350 50  0001 L CNN "Manufacturer"
	1    4400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0207
U 1 1 5F861345
P 10700 6200
F 0 "#PWR0207" H 10700 5950 50  0001 C CNN
F 1 "GND" H 10700 6050 50  0000 C CNN
F 2 "" H 10700 6200 50  0001 C CNN
F 3 "" H 10700 6200 50  0001 C CNN
	1    10700 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 6200 10700 6150
Wire Wire Line
	10800 6000 10800 6150
Wire Wire Line
	10800 6150 10700 6150
Connection ~ 10700 6150
Wire Wire Line
	10700 6150 10700 6000
Wire Wire Line
	10900 6000 10900 6150
Wire Wire Line
	10900 6150 10800 6150
Connection ~ 10800 6150
Wire Wire Line
	4550 5200 4800 5300
Wire Wire Line
	4800 5200 4550 5300
$Comp
L power:+5V #PWR0206
U 1 1 5F869CB1
P 10700 2750
F 0 "#PWR0206" H 10700 2600 50  0001 C CNN
F 1 "+5V" H 10700 2890 50  0000 C CNN
F 2 "" H 10700 2750 50  0001 C CNN
F 3 "" H 10700 2750 50  0001 C CNN
	1    10700 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 2750 10700 2800
Wire Wire Line
	10800 2900 10800 2800
Wire Wire Line
	10800 2800 10700 2800
Connection ~ 10700 2800
Wire Wire Line
	10700 2800 10700 2900
Wire Wire Line
	9100 3550 9100 3500
Wire Wire Line
	9100 3500 9250 3500
Wire Wire Line
	9100 3350 9100 3400
Wire Wire Line
	9100 3400 9250 3400
$Comp
L power:GND #PWR0204
U 1 1 5F8980D8
P 8100 3450
F 0 "#PWR0204" H 8100 3200 50  0001 C CNN
F 1 "GND" H 8100 3300 50  0000 C CNN
F 2 "" H 8100 3450 50  0001 C CNN
F 3 "" H 8100 3450 50  0001 C CNN
	1    8100 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3550 9100 3550
Wire Wire Line
	8550 3350 9100 3350
Wire Wire Line
	8100 3450 8250 3450
$Comp
L MyCrystals:Resonator_Small_vert Y201
U 1 1 5F8A8BD5
P 8450 3450
F 0 "Y201" V 7873 3400 50  0000 C CNN
F 1 "Resonator" V 7964 3400 50  0000 C CNN
F 2 "" H 8425 3450 50  0001 C CNN
F 3 "https://www.murata.com/en/products/productdata/8801162264606/SPEC-CSTNE16M0VH3C000R0.pdf" H 8425 3450 50  0001 C CNN
F 4 "CSTNE16M0VH3C000R0" V 8055 3400 50  0000 C CNN "MPN"
F 5 "490-17951-1-ND" H 8450 3450 50  0001 C CNN "Digi-Key_PN"
F 6 "Y" H 8450 3450 50  0001 C CNN "Prefix"
F 7 "https://www.digikey.com/en/products/detail/murata-electronics/CSTNE16M0VH3C000R0/8747732" H 8450 3450 50  0001 C CNN "Website"
F 8 "CERAMIC RES 16.0000MHZ 15PF SMD" H 8450 3450 50  0001 C CNN "Description"
F 9 "Murata Electronics" H 8450 3450 50  0001 C CNN "Manufacturer"
F 10 "3.2x1.3x0.9mm" V 8146 3400 50  0000 C CNN "Package"
F 11 "16 MHz" V 8237 3400 50  0000 C CNN "Frequency"
	1    8450 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	10800 2800 10900 2800
Wire Wire Line
	10900 2800 10900 2900
Connection ~ 10800 2800
$Comp
L MyCapacitors:C_Small_horizontal C208
U 1 1 5F8AF43A
P 8900 5550
F 0 "C208" H 8800 5350 50  0000 C CNN
F 1 "0.1uF" H 8800 5250 50  0000 C CNN
F 2 "" V 8775 5500 50  0001 L CNN
F 3 "" H 8700 6025 50  0001 L CNN
F 4 "XXXX" H 8800 5150 50  0000 C CNN "Package Size"
F 5 "Voltage" H 8800 5050 50  0000 C CNN "Voltage Rating"
F 6 "MFR P/N" H 8800 4950 50  0000 C CNN "MPN"
F 7 "-" H 8700 5850 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 8700 5850 50  0001 L CNN "Prefix"
F 9 "-" H 8700 5850 50  0001 L CNN "Website"
F 10 "-" H 8700 5850 50  0001 L CNN "Description"
F 11 "-" H 8700 5850 50  0001 L CNN "Manufacturer"
	1    8900 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 5600 9250 5600
$Comp
L power:GND #PWR0205
U 1 1 5F8B38E2
P 8300 5650
F 0 "#PWR0205" H 8300 5400 50  0001 C CNN
F 1 "GND" H 8300 5500 50  0000 C CNN
F 2 "" H 8300 5650 50  0001 C CNN
F 3 "" H 8300 5650 50  0001 C CNN
	1    8300 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 5600 8300 5650
Wire Wire Line
	8300 5600 8700 5600
Wire Wire Line
	4800 5200 9250 5200
Wire Wire Line
	4800 5300 9250 5300
Wire Wire Line
	2050 5200 4550 5200
Wire Wire Line
	2050 5300 4550 5300
Wire Wire Line
	2000 4100 2350 4100
Wire Wire Line
	2000 4600 2000 4100
Wire Wire Line
	2100 4200 2100 4700
Wire Wire Line
	3850 4600 3850 4300
Wire Wire Line
	3950 4700 3950 4400
Wire Wire Line
	2100 4700 3950 4700
Wire Wire Line
	2350 4200 2100 4200
Wire Wire Line
	3850 4600 2000 4600
Wire Wire Line
	3250 4100 3350 4100
$Comp
L power:GND #PWR0202
U 1 1 5F8CB74A
P 3350 4350
F 0 "#PWR0202" H 3350 4100 50  0001 C CNN
F 1 "GND" H 3350 4200 50  0000 C CNN
F 2 "" H 3350 4350 50  0001 C CNN
F 3 "" H 3350 4350 50  0001 C CNN
	1    3350 4350
	1    0    0    -1  
$EndComp
$Comp
L MyConnectors:ISP_Header J202
U 1 1 5F8B5E79
P 2350 4100
F 0 "J202" H 2800 4415 50  0000 C CNN
F 1 "ICSP_Header" H 2800 4324 50  0000 C CNN
F 2 "" H 2600 3750 50  0001 L CNN
F 3 "~" H 2600 3750 50  0001 C CNN
F 4 "MFR P/N" H 2800 4233 50  0000 C CNN "MPN"
F 5 "-" H 2800 4598 50  0001 C CNN "Digi-Key_PN"
F 6 "J" H 2800 4507 50  0001 C CNN "Prefix"
F 7 "-" H 2800 4416 50  0001 C CNN "Website"
F 8 "-" H 2800 4325 50  0001 C CNN "Description"
F 9 "-" H 2800 4234 50  0001 C CNN "Manufacturer"
	1    2350 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 4200 9250 4200
Wire Wire Line
	3950 4400 9250 4400
Wire Wire Line
	3850 4300 9250 4300
Connection ~ 2350 5100
Wire Wire Line
	2350 5100 4200 5100
Connection ~ 9250 4200
Wire Wire Line
	9250 4200 9450 4200
Connection ~ 9250 4300
Wire Wire Line
	9250 4300 9450 4300
Connection ~ 9250 4400
Wire Wire Line
	9250 4400 9450 4400
Wire Wire Line
	2050 5100 2350 5100
Text Label 3350 4100 0    50   ~ 0
V_BUS
Wire Wire Line
	4400 5100 4800 5100
Wire Wire Line
	4800 5050 4800 5100
Connection ~ 4800 5100
Wire Wire Line
	4800 5100 9250 5100
Wire Wire Line
	3350 4300 3350 4350
Wire Wire Line
	3250 4300 3350 4300
Wire Wire Line
	2350 4300 2350 5100
Text Notes 1800 6100 0    50   ~ 0
I expect both the ICSP and FTDI headers to supply 5V, either or, etc.
$EndSCHEMATC
