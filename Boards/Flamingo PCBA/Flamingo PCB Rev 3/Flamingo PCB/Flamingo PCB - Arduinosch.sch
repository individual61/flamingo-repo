EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
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
P 10850 4500
F 0 "U201" H 9550 6050 60  0000 L CNN
F 1 "ATMEGA328P-AU" V 11050 4550 60  0000 C CNN
F 2 "digikey-footprints:TQFP-32_7x7mm" H 11400 4700 60  0001 L CNN
F 3 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 11400 4800 60  0001 L CNN
F 4 "ATMEGA328P-AU-ND" H 11400 4900 60  0001 L CNN "Digi-Key_PN"
F 5 "ATMEGA328P-AU" H 11400 5000 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 11400 5100 60  0001 L CNN "Category"
F 7 "Embedded - Microcontrollers" H 11400 5200 60  0001 L CNN "Family"
F 8 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 11400 5300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/microchip-technology/ATMEGA328P-AU/ATMEGA328P-AU-ND/1832260" H 11400 5400 60  0001 L CNN "DK_Detail_Page"
F 10 "IC MCU 8BIT 32KB FLASH 32TQFP" H 11400 5500 60  0001 L CNN "Description"
F 11 "Microchip Technology" H 11400 5600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 11400 5700 60  0001 L CNN "Status"
F 13 "Derived from DK symbol" H 11850 5950 50  0001 C CNN "Attribution"
	1    10850 4500
	1    0    0    -1  
$EndComp
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
P 2800 4700
F 0 "#PWR0203" H 2800 4550 50  0001 C CNN
F 1 "+5V" H 2800 4840 50  0000 C CNN
F 2 "" H 2800 4700 50  0001 C CNN
F 3 "" H 2800 4700 50  0001 C CNN
	1    2800 4700
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R?
U 1 1 5F8530A4
P 2800 4850
AR Path="/5F780D75/5F8530A4" Ref="R?"  Part="1" 
AR Path="/5F780A01/5F8530A4" Ref="R201"  Part="1" 
F 0 "R201" H 2881 4962 50  0000 L CNN
F 1 "10k" H 2881 4871 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2855 4800 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 2800 4850 50  0001 C CNN
F 4 "0603" H 2881 4780 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 2881 4689 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 2800 4850 50  0001 C CNN "Description"
F 7 "Yageo" H 2800 4850 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 2800 4850 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 2800 4850 50  0001 C CNN "Digi-Key_PN"
	1    2800 4850
	1    0    0    -1  
$EndComp
$Comp
L MyCapacitors:C_Small_horizontal C207
U 1 1 5F85B8E0
P 2400 5050
F 0 "C207" H 2200 5550 50  0000 L CNN
F 1 "0.1uF" H 2200 5450 50  0000 L CNN
F 2 "" V 2275 5000 50  0001 L CNN
F 3 "" H 2200 5525 50  0001 L CNN
F 4 "XXXX" H 2200 5250 50  0000 L CNN "Package Size"
F 5 "Voltage" H 2200 5350 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 2200 5150 50  0000 L CNN "MPN"
F 7 "-" H 2200 5350 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 2200 5350 50  0001 L CNN "Prefix"
F 9 "-" H 2200 5350 50  0001 L CNN "Website"
F 10 "-" H 2200 5350 50  0001 L CNN "Description"
F 11 "-" H 2200 5350 50  0001 L CNN "Manufacturer"
	1    2400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0207
U 1 1 5F861345
P 10850 6200
F 0 "#PWR0207" H 10850 5950 50  0001 C CNN
F 1 "GND" H 10850 6050 50  0000 C CNN
F 2 "" H 10850 6200 50  0001 C CNN
F 3 "" H 10850 6200 50  0001 C CNN
	1    10850 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10850 6200 10850 6150
Wire Wire Line
	10950 6000 10950 6150
Wire Wire Line
	10950 6150 10850 6150
Connection ~ 10850 6150
Wire Wire Line
	10850 6150 10850 6000
Wire Wire Line
	11050 6000 11050 6150
Wire Wire Line
	11050 6150 10950 6150
Connection ~ 10950 6150
Wire Wire Line
	2500 5200 2750 5300
Wire Wire Line
	2750 5200 2500 5300
$Comp
L power:+5V #PWR0206
U 1 1 5F869CB1
P 10850 2750
F 0 "#PWR0206" H 10850 2600 50  0001 C CNN
F 1 "+5V" H 10850 2890 50  0000 C CNN
F 2 "" H 10850 2750 50  0001 C CNN
F 3 "" H 10850 2750 50  0001 C CNN
	1    10850 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10850 2750 10850 2800
Wire Wire Line
	10950 2900 10950 2800
Wire Wire Line
	10950 2800 10850 2800
Connection ~ 10850 2800
Wire Wire Line
	10850 2800 10850 2900
$Comp
L power:GND #PWR0204
U 1 1 5F8980D8
P 7650 3450
F 0 "#PWR0204" H 7650 3200 50  0001 C CNN
F 1 "GND" H 7650 3300 50  0000 C CNN
F 2 "" H 7650 3450 50  0001 C CNN
F 3 "" H 7650 3450 50  0001 C CNN
	1    7650 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 3450 7800 3450
$Comp
L MyCrystals:Resonator_Small_vert Y201
U 1 1 5F8A8BD5
P 8000 3450
F 0 "Y201" V 7423 3400 50  0000 C CNN
F 1 "Resonator" V 7514 3400 50  0000 C CNN
F 2 "" H 7975 3450 50  0001 C CNN
F 3 "https://www.murata.com/en/products/productdata/8801162264606/SPEC-CSTNE16M0VH3C000R0.pdf" H 7975 3450 50  0001 C CNN
F 4 "CSTNE16M0VH3C000R0" V 7605 3400 50  0000 C CNN "MPN"
F 5 "490-17951-1-ND" H 8000 3450 50  0001 C CNN "Digi-Key_PN"
F 6 "Y" H 8000 3450 50  0001 C CNN "Prefix"
F 7 "https://www.digikey.com/en/products/detail/murata-electronics/CSTNE16M0VH3C000R0/8747732" H 8000 3450 50  0001 C CNN "Website"
F 8 "CERAMIC RES 16.0000MHZ 15PF SMD" H 8000 3450 50  0001 C CNN "Description"
F 9 "Murata Electronics" H 8000 3450 50  0001 C CNN "Manufacturer"
F 10 "3.2x1.3x0.9mm" V 7696 3400 50  0000 C CNN "Package"
F 11 "16 MHz" V 7787 3400 50  0000 C CNN "Frequency"
	1    8000 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	10950 2800 11050 2800
Wire Wire Line
	11050 2800 11050 2900
Connection ~ 10950 2800
$Comp
L MyCapacitors:C_Small_horizontal C208
U 1 1 5F8AF43A
P 8400 5550
F 0 "C208" H 8300 5350 50  0000 C CNN
F 1 "0.1uF" H 8300 5250 50  0000 C CNN
F 2 "" V 8275 5500 50  0001 L CNN
F 3 "" H 8200 6025 50  0001 L CNN
F 4 "XXXX" H 8300 5150 50  0000 C CNN "Package Size"
F 5 "Voltage" H 8300 5050 50  0000 C CNN "Voltage Rating"
F 6 "MFR P/N" H 8300 4950 50  0000 C CNN "MPN"
F 7 "-" H 8200 5850 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 8200 5850 50  0001 L CNN "Prefix"
F 9 "-" H 8200 5850 50  0001 L CNN "Website"
F 10 "-" H 8200 5850 50  0001 L CNN "Description"
F 11 "-" H 8200 5850 50  0001 L CNN "Manufacturer"
	1    8400 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0205
U 1 1 5F8B38E2
P 8050 5650
F 0 "#PWR0205" H 8050 5400 50  0001 C CNN
F 1 "GND" H 8050 5500 50  0000 C CNN
F 2 "" H 8050 5650 50  0001 C CNN
F 3 "" H 8050 5650 50  0001 C CNN
	1    8050 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5600 8050 5650
Wire Wire Line
	8050 5600 8200 5600
Wire Wire Line
	2800 5050 2800 5100
$Comp
L Device:C C?
U 1 1 5F85650D
P 4800 7150
F 0 "C?" H 4915 7196 50  0000 L CNN
F 1 "10uF" H 4915 7105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4838 7000 50  0001 C CNN
F 3 "~" H 4800 7150 50  0001 C CNN
F 4 "-" H 4800 7150 50  0001 C CNN "Description"
F 5 "GRM21BR61C106KE15L" H 5250 6900 50  0000 C CNN "MPN"
F 6 "-" H 4800 7150 50  0001 C CNN "Manufacturer"
F 7 "-" H 4800 7150 50  0001 C CNN "Website"
F 8 "-" H 4800 7150 50  0001 C CNN "Digi-Key_PN"
F 9 "0805" H 5000 7000 50  0000 C CNN "Package"
F 10 "16V" H 4800 7150 50  0001 C CNN "Voltage Rating"
	1    4800 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F856F35
P 7700 1400
F 0 "C?" H 7815 1446 50  0000 L CNN
F 1 "100uF" H 7815 1355 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-C_EIA-6032-28_Reflow" H 7738 1250 50  0001 C CNN
F 3 "~" H 7700 1400 50  0001 C CNN
F 4 "-" H 7700 1400 50  0001 C CNN "Description"
F 5 "TAJC107K010RNJ" H 8150 1150 50  0000 C CNN "MPN"
F 6 "-" H 7700 1400 50  0001 C CNN "Manufacturer"
F 7 "-" H 7700 1400 50  0001 C CNN "Website"
F 8 "-" H 7700 1400 50  0001 C CNN "Digi-Key_PN"
F 9 "2312" H 7900 1250 50  0000 C CNN "Package"
F 10 "10V" H 7700 1400 50  0001 C CNN "Voltage Rating"
	1    7700 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F85C2DB
P 700 7150
F 0 "C?" H 815 7196 50  0000 L CNN
F 1 "0.1uF" H 815 7105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 738 7000 50  0001 C CNN
F 3 "http://datasheets.avx.com/FlexitermMLCC.pdf" H 700 7150 50  0001 C CNN
F 4 "CAP CER 0.1UF 50V X7R 0603" H 700 7150 50  0001 C CNN "Description"
F 5 "06035C104KAZ2A" H 1150 6900 50  0000 C CNN "MPN"
F 6 "AVX Corporation" H 700 7150 50  0001 C CNN "Manufacturer"
F 7 "https://www.digikey.com/en/products/detail/avx-corporation/06035C104KAZ2A/1024893" H 700 7150 50  0001 C CNN "Website"
F 8 "478-3540-1-ND" H 700 7150 50  0001 C CNN "Digi-Key_PN"
F 9 "0603" H 900 7000 50  0000 C CNN "Package"
F 10 "50V" H 700 7150 50  0001 C CNN "Voltage Rating"
	1    700  7150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F85BEA0
P 1650 7150
F 0 "C?" H 1765 7196 50  0000 L CNN
F 1 "0.1uF" H 1765 7105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1688 7000 50  0001 C CNN
F 3 "http://datasheets.avx.com/FlexitermMLCC.pdf" H 1650 7150 50  0001 C CNN
F 4 "CAP CER 0.1UF 50V X7R 0603" H 1650 7150 50  0001 C CNN "Description"
F 5 "06035C104KAZ2A" H 2100 6900 50  0000 C CNN "MPN"
F 6 "AVX Corporation" H 1650 7150 50  0001 C CNN "Manufacturer"
F 7 "https://www.digikey.com/en/products/detail/avx-corporation/06035C104KAZ2A/1024893" H 1650 7150 50  0001 C CNN "Website"
F 8 "478-3540-1-ND" H 1650 7150 50  0001 C CNN "Digi-Key_PN"
F 9 "0603" H 1850 7000 50  0000 C CNN "Package"
F 10 "50V" H 1650 7150 50  0001 C CNN "Voltage Rating"
	1    1650 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F85BAAD
P 2500 7150
F 0 "C?" H 2615 7196 50  0000 L CNN
F 1 "0.1uF" H 2615 7105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2538 7000 50  0001 C CNN
F 3 "http://datasheets.avx.com/FlexitermMLCC.pdf" H 2500 7150 50  0001 C CNN
F 4 "CAP CER 0.1UF 50V X7R 0603" H 2500 7150 50  0001 C CNN "Description"
F 5 "06035C104KAZ2A" H 2950 6900 50  0000 C CNN "MPN"
F 6 "AVX Corporation" H 2500 7150 50  0001 C CNN "Manufacturer"
F 7 "https://www.digikey.com/en/products/detail/avx-corporation/06035C104KAZ2A/1024893" H 2500 7150 50  0001 C CNN "Website"
F 8 "478-3540-1-ND" H 2500 7150 50  0001 C CNN "Digi-Key_PN"
F 9 "0603" H 2700 7000 50  0000 C CNN "Package"
F 10 "50V" H 2500 7150 50  0001 C CNN "Voltage Rating"
	1    2500 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F857E6A
P 3350 7150
F 0 "C?" H 3465 7196 50  0000 L CNN
F 1 "0.1uF" H 3465 7105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3388 7000 50  0001 C CNN
F 3 "http://datasheets.avx.com/FlexitermMLCC.pdf" H 3350 7150 50  0001 C CNN
F 4 "CAP CER 0.1UF 50V X7R 0603" H 3350 7150 50  0001 C CNN "Description"
F 5 "06035C104KAZ2A" H 3800 6900 50  0000 C CNN "MPN"
F 6 "AVX Corporation" H 3350 7150 50  0001 C CNN "Manufacturer"
F 7 "https://www.digikey.com/en/products/detail/avx-corporation/06035C104KAZ2A/1024893" H 3350 7150 50  0001 C CNN "Website"
F 8 "478-3540-1-ND" H 3350 7150 50  0001 C CNN "Digi-Key_PN"
F 9 "0603" H 3550 7000 50  0000 C CNN "Package"
F 10 "50V" H 3350 7150 50  0001 C CNN "Voltage Rating"
	1    3350 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  7000 700  6900
Wire Wire Line
	700  6900 1650 6900
Wire Wire Line
	3350 6900 3350 7000
Wire Wire Line
	700  7300 700  7500
Wire Wire Line
	700  7500 1650 7500
Wire Wire Line
	3350 7500 3350 7300
Wire Wire Line
	2500 7300 2500 7500
Connection ~ 2500 7500
Wire Wire Line
	2500 7500 3350 7500
Wire Wire Line
	1650 7300 1650 7500
Connection ~ 1650 7500
Wire Wire Line
	1650 7500 2000 7500
Wire Wire Line
	1650 7000 1650 6900
Connection ~ 1650 6900
Wire Wire Line
	1650 6900 2100 6900
Wire Wire Line
	2500 7000 2500 6900
Connection ~ 2500 6900
Wire Wire Line
	2500 6900 3350 6900
$Comp
L power:GND #PWR?
U 1 1 5F8726F7
P 2000 7500
F 0 "#PWR?" H 2000 7250 50  0001 C CNN
F 1 "GND" H 2000 7350 50  0000 C CNN
F 2 "" H 2000 7500 50  0001 C CNN
F 3 "" H 2000 7500 50  0001 C CNN
	1    2000 7500
	1    0    0    -1  
$EndComp
Connection ~ 2000 7500
Wire Wire Line
	2000 7500 2500 7500
$Comp
L power:+5V #PWR?
U 1 1 5F872CDF
P 2100 6800
F 0 "#PWR?" H 2100 6650 50  0001 C CNN
F 1 "+5V" H 2100 6940 50  0000 C CNN
F 2 "" H 2100 6800 50  0001 C CNN
F 3 "" H 2100 6800 50  0001 C CNN
	1    2100 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 6800 2100 6900
Connection ~ 2100 6900
Wire Wire Line
	2100 6900 2500 6900
Text HLabel 3350 4100 2    50   UnSpc ~ 10
V_BUS
Wire Wire Line
	2050 5400 3250 5400
Wire Wire Line
	3250 4100 3350 4100
Wire Wire Line
	3300 4300 9400 4300
Wire Wire Line
	3300 4450 3300 4300
$Comp
L power:GND #PWR0202
U 1 1 5F8CB74A
P 3000 4300
F 0 "#PWR0202" H 3000 4050 50  0001 C CNN
F 1 "GND" H 3000 4150 50  0000 C CNN
F 2 "" H 3000 4300 50  0001 C CNN
F 3 "" H 3000 4300 50  0001 C CNN
	1    3000 4300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 5100 2100 5100
Wire Wire Line
	2100 4300 2100 5100
$Comp
L MyConnectors:ISP_Header J202
U 1 1 5F8B5E79
P 2100 4100
F 0 "J202" H 2550 4415 50  0000 C CNN
F 1 "ICSP_Header" H 2550 4324 50  0000 C CNN
F 2 "" H 2350 3750 50  0001 L CNN
F 3 "~" H 2350 3750 50  0001 C CNN
F 4 "MFR P/N" H 2550 4233 50  0000 C CNN "MPN"
F 5 "-" H 2550 4598 50  0001 C CNN "Digi-Key_PN"
F 6 "J" H 2550 4507 50  0001 C CNN "Prefix"
F 7 "-" H 2550 4416 50  0001 C CNN "Website"
F 8 "-" H 2550 4325 50  0001 C CNN "Description"
F 9 "-" H 2550 4234 50  0001 C CNN "Manufacturer"
	1    2100 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4200 2050 4200
Wire Wire Line
	2000 4100 2100 4100
Wire Wire Line
	3000 4100 3250 4100
Connection ~ 3250 4100
Wire Wire Line
	3250 4100 3250 5400
Wire Wire Line
	2000 4450 2000 4100
Wire Wire Line
	2050 4200 2050 4400
Wire Wire Line
	2050 4400 9400 4400
Text Notes 700  6750 0    50   ~ 0
Place next to VCC pins
Wire Wire Line
	3000 4200 9400 4200
Wire Wire Line
	2100 5100 2200 5100
Connection ~ 2100 5100
Wire Wire Line
	2400 5100 2800 5100
Wire Wire Line
	2800 5100 9400 5100
Connection ~ 2800 5100
Wire Wire Line
	2000 4450 3300 4450
Wire Wire Line
	2050 5200 2500 5200
Wire Wire Line
	2050 5300 2500 5300
Wire Wire Line
	2750 5200 9400 5200
Wire Wire Line
	2750 5300 9400 5300
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 5F9B2DF6
P 6400 1450
F 0 "J?" H 6318 1025 50  0000 C CNN
F 1 "APA102 HEADER" H 6318 1116 50  0000 C CNN
F 2 "" H 6400 1450 50  0001 C CNN
F 3 "~" H 6400 1450 50  0001 C CNN
F 4 "MPN" H 6400 1450 50  0001 C CNN "MPN"
F 5 "-" H 6400 1450 50  0001 C CNN "Digi-Key_PN"
F 6 "-" H 6400 1450 50  0001 C CNN "Website"
F 7 "-" H 6400 1450 50  0001 C CNN "Description"
F 8 "-" H 6400 1450 50  0001 C CNN "Manufacturer"
	1    6400 1450
	-1   0    0    1   
$EndComp
Wire Wire Line
	10000 1350 10000 1450
$Comp
L MyLEDs:LED_ALT_vert D?
U 1 1 5F9CDB9E
P 10000 1200
AR Path="/5F780D75/5F9CDB9E" Ref="D?"  Part="1" 
AR Path="/5F780F7E/5F9CDB9E" Ref="D?"  Part="1" 
AR Path="/5F780A01/5F9CDB9E" Ref="D?"  Part="1" 
F 0 "D?" H 10118 1330 50  0000 L CNN
F 1 "Orange/Heartbeat" H 10118 1239 50  0000 L CNN
F 2 "LEDs:LED_0603_HandSoldering" H 10100 1200 50  0001 C CNN
F 3 "https://dammedia.osram.info/media/resource/hires/osram-dam-2493882/LO%20L29K.pdf" H 10200 1300 50  0001 C CNN
F 4 "0603" H 10118 1148 50  0000 L CNN "Package Size"
F 5 "LO L29K-H2K1-24-Z" H 10118 1057 50  0000 L CNN "MFR P/N"
F 6 "LED ORANGE DIFFUSED 0603 SMD" H 10000 1200 50  0001 C CNN "Description"
F 7 "OSRAM Opto Semiconductors Inc." H 10000 1200 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/osram-opto-semiconductors-inc/LO-L29K-H2K1-24-Z/1938771" H 10000 1200 50  0001 C CNN "Website"
F 9 "475-2740-1-ND" H 10000 1200 50  0001 C CNN "Digi-Key_PN"
	1    10000 1200
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R?
U 1 1 5F9CDBAA
P 10000 1600
AR Path="/5F780D75/5F9CDBAA" Ref="R?"  Part="1" 
AR Path="/5F780F7E/5F9CDBAA" Ref="R?"  Part="1" 
AR Path="/5F780A01/5F9CDBAA" Ref="R?"  Part="1" 
F 0 "R?" H 10081 1712 50  0000 L CNN
F 1 "1.5k" H 10081 1621 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 10055 1550 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 10000 1600 50  0001 C CNN
F 4 "0603" H 10081 1530 50  0000 L CNN "Package Size"
F 5 "RC0603FR-071K5L" H 10081 1439 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 1.5K OHM 1% 1/10W 0603" H 10000 1600 50  0001 C CNN "Description"
F 7 "Yageo" H 10000 1600 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603FR-071K5L/729811" H 10000 1600 50  0001 C CNN "Website"
F 9 "311-1.50KHRCT-ND" H 10000 1600 50  0001 C CNN "Digi-Key_PN"
	1    10000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 1000 10000 1050
$Comp
L power:GND #PWR?
U 1 1 5F9D1FE5
P 10000 1900
F 0 "#PWR?" H 10000 1650 50  0001 C CNN
F 1 "GND" H 10000 1750 50  0000 C CNN
F 2 "" H 10000 1900 50  0001 C CNN
F 3 "" H 10000 1900 50  0001 C CNN
	1    10000 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 1900 10000 1800
Text Label 9700 1000 2    50   ~ 10
Heartbeat_LED
Wire Wire Line
	9700 1000 10000 1000
$Comp
L power:GND #PWR?
U 1 1 5F9E548C
P 7700 1700
F 0 "#PWR?" H 7700 1450 50  0001 C CNN
F 1 "GND" H 7700 1550 50  0000 C CNN
F 2 "" H 7700 1700 50  0001 C CNN
F 3 "" H 7700 1700 50  0001 C CNN
	1    7700 1700
	1    0    0    -1  
$EndComp
Text Label 9050 4200 2    50   ~ 10
MOSI__APA102DATA
Text Label 9050 4300 2    50   ~ 10
MISO
Wire Wire Line
	9250 3200 9400 3200
Wire Wire Line
	9250 3300 9400 3300
Wire Wire Line
	8100 3350 8250 3350
Wire Wire Line
	8250 3350 8250 3400
Wire Wire Line
	8250 3400 9400 3400
Wire Wire Line
	8100 3550 8250 3550
Wire Wire Line
	8250 3550 8250 3500
Wire Wire Line
	8250 3500 9400 3500
Text Label 9050 4400 2    50   ~ 10
SCK__APA102CLOCK
Text Label 6700 1350 0    50   ~ 10
SCK__APA102CLOCK
Text Label 6700 1450 0    50   ~ 10
MOSI__APA102DATA
Text Notes 6800 850  0    50   ~ 10
TODO: \nSELECT CONNECTOR\nCHECK PINOUT
Wire Wire Line
	7700 1700 7700 1550
Wire Wire Line
	7850 1000 7700 1000
Wire Wire Line
	7700 1000 7700 1250
Wire Wire Line
	7450 1250 7700 1250
Connection ~ 7700 1250
Wire Wire Line
	7450 1550 7700 1550
Connection ~ 7700 1550
Text HLabel 9050 4900 0    50   UnSpc ~ 10
SDA_IMU_5V
Text HLabel 9050 5000 0    50   UnSpc ~ 10
SCL_IMU_5V
Wire Wire Line
	9050 4900 9400 4900
Wire Wire Line
	9050 5000 9400 5000
Text HLabel 3850 1050 0    50   UnSpc ~ 10
V_OUT
Wire Wire Line
	3850 1050 4050 1050
Text Label 9150 5700 2    50   ~ 10
Volt_sens_divider
Text HLabel 9200 5400 0    50   UnSpc ~ 10
IMU_INTERRUPT_5V
Text Label 9050 4500 2    50   ~ 10
Heartbeat_LED
Wire Wire Line
	9250 3600 9400 3600
Text Notes -1600 -700 0    50   ~ 0
ADXL345         2 interrupt pins                  i2c             acc only\nICM20948        1 interrupt pin                   i2c/aux       acc gyro mag\nMPU6050        1 interrupt pin                    i2c            ACC GYRO\nBNO055          1 interrupt pin, 1 reset pin      i2c            acc gyro mag\n
Text Notes 550  950  0    50   ~ 10
TODO: \n\nSELECT CONNECTOR FOR BUTTON BOARD CABLE.\nUSE AS MANY POSITIONS AS THERE ARE FREE PINS, \nSO THIS CAN BE AN EXTENSION HEADER
$Comp
L power:+5V #PWR?
U 1 1 5F861215
P 4800 6850
F 0 "#PWR?" H 4800 6700 50  0001 C CNN
F 1 "+5V" H 4800 6990 50  0000 C CNN
F 2 "" H 4800 6850 50  0001 C CNN
F 3 "" H 4800 6850 50  0001 C CNN
	1    4800 6850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F86171A
P 4800 7400
F 0 "#PWR?" H 4800 7150 50  0001 C CNN
F 1 "GND" H 4800 7250 50  0000 C CNN
F 2 "" H 4800 7400 50  0001 C CNN
F 3 "" H 4800 7400 50  0001 C CNN
	1    4800 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 7400 4800 7300
Wire Wire Line
	4800 6850 4800 7000
Text Notes 5000 6800 0    50   ~ 0
Place next to VCC pins
Text Label 9250 3200 2    50   ~ 10
Button_1
Text Label 9250 3300 2    50   ~ 10
Button_2
Text Label 9250 3600 2    50   ~ 10
Button_3
Text Notes 2950 -450 0    50   ~ 0
Ideas:\n\nOne on-board button for convenience. (adds a resistor and a button)\nDIP switch (adds resistor per switch)
Text Label 1700 1500 0    50   ~ 10
Button_1
Text Label 1700 1600 0    50   ~ 10
Button_2
Text Label 1700 1700 0    50   ~ 10
Button_3
Text HLabel 1700 1400 2    50   Input ~ 10
V_OUT
$Comp
L power:GND #PWR?
U 1 1 5F875030
P 1700 1800
F 0 "#PWR?" H 1700 1550 50  0001 C CNN
F 1 "GND" H 1700 1650 50  0000 C CNN
F 2 "" H 1700 1800 50  0001 C CNN
F 3 "" H 1700 1800 50  0001 C CNN
	1    1700 1800
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5F87A6A8
P 950 1600
F 0 "J?" H 868 1175 50  0000 C CNN
F 1 "Button Board Connector" H 868 1266 50  0000 C CNN
F 2 "" H 950 1600 50  0001 C CNN
F 3 "~" H 950 1600 50  0001 C CNN
	1    950  1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	1150 1400 1700 1400
Wire Wire Line
	1150 1500 1700 1500
Wire Wire Line
	1150 1800 1700 1800
Wire Wire Line
	1150 1700 1700 1700
Wire Wire Line
	1150 1600 1700 1600
Wire Wire Line
	8400 5600 9400 5600
Wire Wire Line
	9150 5700 9400 5700
Wire Wire Line
	9050 4500 9400 4500
Wire Wire Line
	9400 5400 9200 5400
Text HLabel 7850 1000 2    50   Input ~ 10
V_OUT
Text Notes 9300 1700 0    31   ~ 6
Vf = 1.8V, 2 mA Ityp\n5V-1.8 = 3.2V\n3.2V/1.5k = 2.1 mA
Text HLabel 9050 4600 0    50   UnSpc ~ 10
V_BUS
Text Notes 4750 4700 0    50   ~ 0
Sensing USB power or not: V_BUS will be pulled to GND through 100k when there is nothing on USB.\nUse digital read to determine.
Wire Wire Line
	9050 4600 9400 4600
Text Notes 2900 2750 0    50   ~ 0
If we use V_OUT, we can sense batt voltage up to 4.2 V, \nand if USB is connected, we can use an additional\n digital pin to sense that line.
Text Notes 3000 950  0    50   ~ 10
TODO: \nVOLTAGE DIVIDE SO THAT 4.2 V ENDS UP JUST BELOW 1.1 V \n(internal voltage reference for ADC)\n\nCHOOSE PIN
Wire Wire Line
	4050 1650 4050 1750
Connection ~ 4050 1650
Wire Wire Line
	4300 1650 4050 1650
Text Label 4300 1650 0    50   ~ 10
Volt_sens_divider
Wire Wire Line
	4050 2200 4050 2100
$Comp
L power:GND #PWR?
U 1 1 5FA79585
P 4050 2200
F 0 "#PWR?" H 4050 1950 50  0001 C CNN
F 1 "GND" H 4050 2050 50  0000 C CNN
F 2 "" H 4050 2200 50  0001 C CNN
F 3 "" H 4050 2200 50  0001 C CNN
	1    4050 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1050 4050 1200
Wire Wire Line
	4050 1550 4050 1650
$Comp
L MyResistors:R_vert R?
U 1 1 5FA738C9
P 4050 1350
AR Path="/5F780D75/5FA738C9" Ref="R?"  Part="1" 
AR Path="/5F780F7E/5FA738C9" Ref="R?"  Part="1" 
AR Path="/5F780A01/5FA738C9" Ref="R?"  Part="1" 
F 0 "R?" H 4131 1462 50  0000 L CNN
F 1 "-" H 4131 1371 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4105 1300 50  0001 C CNN
F 3 "" H 4050 1350 50  0001 C CNN
F 4 "0603" H 4131 1280 50  0000 L CNN "Package Size"
F 5 "" H 4131 1189 50  0000 L CNN "MFR P/N"
F 6 "" H 4050 1350 50  0001 C CNN "Description"
F 7 "" H 4050 1350 50  0001 C CNN "Manufacturer"
F 8 "" H 4050 1350 50  0001 C CNN "Website"
F 9 "" H 4050 1350 50  0001 C CNN "Digi-Key_PN"
	1    4050 1350
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R?
U 1 1 5FA70FC9
P 4050 1900
AR Path="/5F780D75/5FA70FC9" Ref="R?"  Part="1" 
AR Path="/5F780F7E/5FA70FC9" Ref="R?"  Part="1" 
AR Path="/5F780A01/5FA70FC9" Ref="R?"  Part="1" 
F 0 "R?" H 4131 2012 50  0000 L CNN
F 1 "-" H 4131 1921 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4105 1850 50  0001 C CNN
F 3 "" H 4050 1900 50  0001 C CNN
F 4 "0603" H 4131 1830 50  0000 L CNN "Package Size"
F 5 "" H 4131 1739 50  0000 L CNN "MFR P/N"
F 6 "" H 4050 1900 50  0001 C CNN "Description"
F 7 "" H 4050 1900 50  0001 C CNN "Manufacturer"
F 8 "" H 4050 1900 50  0001 C CNN "Website"
F 9 "" H 4050 1900 50  0001 C CNN "Digi-Key_PN"
	1    4050 1900
	1    0    0    -1  
$EndComp
Wire Notes Line
	2700 500  2700 2850
Wire Notes Line
	5750 500  5750 2800
Wire Notes Line
	8650 500  8650 2750
$EndSCHEMATC
