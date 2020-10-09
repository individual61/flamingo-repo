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
L dk_Embedded-Microcontrollers:ATMEGA328P-AU U?
U 1 1 5F81C685
P 5400 2900
F 0 "U?" H 5728 3003 60  0000 L CNN
F 1 "ATMEGA328P-AU" H 5728 2897 60  0000 L CNN
F 2 "digikey-footprints:TQFP-32_7x7mm" H 5600 3100 60  0001 L CNN
F 3 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 5600 3200 60  0001 L CNN
F 4 "ATMEGA328P-AU-ND" H 5600 3300 60  0001 L CNN "Digi-Key_PN"
F 5 "ATMEGA328P-AU" H 5600 3400 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 5600 3500 60  0001 L CNN "Category"
F 7 "Embedded - Microcontrollers" H 5600 3600 60  0001 L CNN "Family"
F 8 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en608326" H 5600 3700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/microchip-technology/ATMEGA328P-AU/ATMEGA328P-AU-ND/1832260" H 5600 3800 60  0001 L CNN "DK_Detail_Page"
F 10 "IC MCU 8BIT 32KB FLASH 32TQFP" H 5600 3900 60  0001 L CNN "Description"
F 11 "Microchip Technology" H 5600 4000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5600 4100 60  0001 L CNN "Status"
	1    5400 2900
	1    0    0    -1  
$EndComp
$EndSCHEMATC
