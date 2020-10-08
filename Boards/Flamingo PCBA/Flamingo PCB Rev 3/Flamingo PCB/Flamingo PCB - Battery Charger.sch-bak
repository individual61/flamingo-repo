EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 600  7550 0    39   ~ 0
--------FLOW CHART--------\n\n###SHUTDOWN MODE\nVDD < VUVLO\nVDD < VBAT\nor\nPROG > 200 k\nSTAT = High Z\n\n###PRECONDITIONING \nCharge Current = IPREG\nSTAT = LOW\n\n###FAST CHARGE \nAlso get here if VBAT > VPTH from SHUTDOWN    \nor   \nVBAT < VRTH  from CHARGE COMPLETE\n\nCharge Current = IREG\nSTAT = LOW\n\n###CONSTANT VOLTAGE \nCharge Voltage = VREG\nSTAT = LOW\n\n###CHARGE MODE \nSTAT = HIGH (MCP73831)\nSTAT = High Z (MCP73832)\n\n--------PART NUMBER BREAKDOWN--------\n\nMCP73831T - 2 * * * _ OT\n\n(T) Tape and reel\n(2) 4.20 V regulated\n(OT) SMall Outline Transistor SOT23 T-Lead\n\n#######\n\nMCP73831T - 2 A C I _ OT\n(AT) Ipreg/Ireg = 10%\n        Iterm/Ireg = 7.5%\n\nMCP73831T - 2 A T I _ OT\n(AT) Ipreg/Ireg = 10%\n        Iterm/Ireg = 20%\n\nMCP73831T - 2 D C I _ OT\n(DC) Ipreg/Ireg = 100%\n        Iterm/Ireg = 7.5%
$Comp
L dk_PMIC-Battery-Chargers:MCP73831T-2ATI_OT U301
U 1 1 5F7DB625
P 5750 2150
F 0 "U301" H 5750 2553 60  0000 C CNN
F 1 "MCP73831T-2ATI_OT" H 5750 2447 60  0000 C CNN
F 2 "digikey-footprints:SOT-753" H 5950 2350 60  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001984g.pdf" H 5950 2450 60  0001 L CNN
F 4 "MCP73831T-2ATI/OTCT-ND" H 5950 2550 60  0001 L CNN "Digi-Key_PN"
F 5 "MCP73831T-2ATI/OT" H 5950 2650 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 5950 2750 60  0001 L CNN "Category"
F 7 "PMIC - Battery Chargers" H 5950 2850 60  0001 L CNN "Family"
F 8 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001984g.pdf" H 5950 2950 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/microchip-technology/MCP73831T-2ATI-OT/MCP73831T-2ATI-OTCT-ND/1979803" H 5950 3050 60  0001 L CNN "DK_Detail_Page"
F 10 "IC CONTROLLR LI-ION 4.2V SOT23-5" H 5950 3150 60  0001 L CNN "Description"
F 11 "Microchip Technology" H 5950 3250 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5950 3350 60  0001 L CNN "Status"
	1    5750 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0303
U 1 1 5F7DD8CE
P 5750 2550
F 0 "#PWR0303" H 5750 2300 50  0001 C CNN
F 1 "GND" H 5755 2377 50  0000 C CNN
F 2 "" H 5750 2550 50  0001 C CNN
F 3 "" H 5750 2550 50  0001 C CNN
	1    5750 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0304
U 1 1 5F7E1F62
P 6400 3900
F 0 "#PWR0304" H 6400 3650 50  0001 C CNN
F 1 "GND" H 6405 3727 50  0000 C CNN
F 2 "" H 6400 3900 50  0001 C CNN
F 3 "" H 6400 3900 50  0001 C CNN
	1    6400 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0305
U 1 1 5F7E390B
P 7000 2500
F 0 "#PWR0305" H 7000 2250 50  0001 C CNN
F 1 "GND" H 7005 2327 50  0000 C CNN
F 2 "" H 7000 2500 50  0001 C CNN
F 3 "" H 7000 2500 50  0001 C CNN
	1    7000 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 2150 7000 2300
Connection ~ 7000 2150
$Comp
L power:GND #PWR0306
U 1 1 5F7E6098
P 8300 2300
F 0 "#PWR0306" H 8300 2050 50  0001 C CNN
F 1 "GND" H 8305 2127 50  0000 C CNN
F 2 "" H 8300 2300 50  0001 C CNN
F 3 "" H 8300 2300 50  0001 C CNN
	1    8300 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1650 7000 2150
Wire Wire Line
	7100 1650 7100 1800
Text HLabel 8600 1800 2    50   UnSpc ~ 10
V_BAT
Wire Wire Line
	6150 2250 6350 2250
Connection ~ 2250 1950
$Comp
L power:GND #PWR0301
U 1 1 5F7ED2F5
P 2250 2450
F 0 "#PWR0301" H 2250 2200 50  0001 C CNN
F 1 "GND" H 2255 2277 50  0000 C CNN
F 2 "" H 2250 2450 50  0001 C CNN
F 3 "" H 2250 2450 50  0001 C CNN
	1    2250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4200 3650 4400
$Comp
L power:GND #PWR0302
U 1 1 5F7EC089
P 3650 4400
F 0 "#PWR0302" H 3650 4150 50  0001 C CNN
F 1 "GND" H 3655 4227 50  0000 C CNN
F 2 "" H 3650 4400 50  0001 C CNN
F 3 "" H 3650 4400 50  0001 C CNN
	1    3650 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3750 3650 3900
Wire Wire Line
	3650 2400 3650 2650
$Comp
L MyLEDs:LED_ALT_vert D301
U 1 1 5F7EA956
P 3650 2250
F 0 "D301" H 3768 2380 50  0000 L CNN
F 1 "Red/Charging" H 3768 2289 50  0000 L CNN
F 2 "LEDs:LED_0603_HandSoldering" H 3750 2250 50  0001 C CNN
F 3 "https://dammedia.osram.info/media/resource/hires/osram-dam-2493517/LS%20L29K.pdf" H 3850 2350 50  0001 C CNN
F 4 "0603" H 3768 2198 50  0000 L CNN "Package Size"
F 5 "LS L29K-G1J2-1-Z" H 3768 2107 50  0000 L CNN "MFR P/N"
F 6 "LED RED DIFFUSED 0603 SMD" H 3650 2250 50  0001 C CNN "Description"
F 7 "OSRAM Opto Semiconductors Inc." H 3650 2250 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/osram-opto-semiconductors-inc/LS-L29K-G1J2-1-Z/1802633" H 3650 2250 50  0001 C CNN "Website"
F 9 "475-2506-1-ND" H 3650 2250 50  0001 C CNN "Digi-Key_PN"
	1    3650 2250
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R301
U 1 1 5F7EA095
P 3650 2800
F 0 "R301" H 3731 2912 50  0000 L CNN
F 1 "1.5k" H 3731 2821 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3705 2750 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 3650 2800 50  0001 C CNN
F 4 "0603" H 3731 2730 50  0000 L CNN "Package Size"
F 5 "RC0603FR-071K5L" H 3731 2639 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 1.5K OHM 1% 1/10W 0603" H 3650 2800 50  0001 C CNN "Description"
F 7 "Yageo" H 3650 2800 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603FR-071K5L/729811" H 3650 2800 50  0001 C CNN "Website"
F 9 "311-1.50KHRCT-ND" H 3650 2800 50  0001 C CNN "Digi-Key_PN"
	1    3650 2800
	1    0    0    -1  
$EndComp
$Comp
L MyLEDs:LED_ALT_vert D302
U 1 1 5F7E8AF6
P 3650 4050
F 0 "D302" H 3767 4180 50  0000 L CNN
F 1 "Green/Done" H 3767 4089 50  0000 L CNN
F 2 "" H 3750 4050 50  0001 C CNN
F 3 "https://dammedia.osram.info/media/resource/hires/osram-dam-2493945/LG%20L29K.pdf" H 3850 4150 50  0001 C CNN
F 4 "0603" H 3767 3998 50  0000 L CNN "Package Size"
F 5 "LG L29K-F2J1-24-Z" H 3767 3907 50  0000 L CNN "MFR P/N"
F 6 "LED GREEN DIFFUSED 0603 SMD" H 3650 4050 50  0001 C CNN "Description"
F 7 "OSRAM Opto Semiconductors Inc." H 3650 4050 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/osram-opto-semiconductors-inc/LG-L29K-F2J1-24-Z/2513791" H 3650 4050 50  0001 C CNN "Website"
F 9 "475-3118-1-ND" H 3650 4050 50  0001 C CNN "Digi-Key_PN"
	1    3650 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3000 3650 3250
Connection ~ 3650 3250
Wire Wire Line
	3650 3250 3650 3400
Text HLabel 1950 1950 0    50   UnSpc ~ 10
V_BUS
Wire Wire Line
	1950 1950 2050 1950
Wire Wire Line
	2250 2100 2250 1950
Wire Wire Line
	3650 2100 3650 1950
Wire Wire Line
	2250 2450 2250 2300
$Comp
L power:PWR_FLAG #FLG0301
U 1 1 5F839ABA
P 2050 1950
F 0 "#FLG0301" H 2050 2025 50  0001 C CNN
F 1 "PWR_FLAG" H 2050 2123 50  0000 C CNN
F 2 "" H 2050 1950 50  0001 C CNN
F 3 "~" H 2050 1950 50  0001 C CNN
	1    2050 1950
	1    0    0    -1  
$EndComp
Connection ~ 2050 1950
Wire Wire Line
	2050 1950 2250 1950
Text Notes 2750 2950 0    50   ~ 0
Vf = 1.8V, 2 mA Ityp\n5V-1.8 = 3.2V\n3.2V/1.5k = 2.1 mA
Connection ~ 3650 1950
Text Notes 3750 3200 0    50   ~ 0
HIGH when charging is done
Text Notes 350  -300 0    50   ~ 0
A search for 0603 OSRAM leds\n\nhttps://www.digikey.com/short/zwdccj\nBlue\nGreen\norange\nRed\nWhite\nWhite Cool\nYellow
$Comp
L MyResistors:R_vert R302
U 1 1 5F7F1D0C
P 3650 3550
F 0 "R302" H 3731 3662 50  0000 L CNN
F 1 "1.5k" H 3731 3571 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3705 3500 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 3650 3550 50  0001 C CNN
F 4 "0603" H 3731 3480 50  0000 L CNN "Package Size"
F 5 "RC0603FR-071K5L" H 3731 3389 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 1.5K OHM 1% 1/10W 0603" H 3650 3550 50  0001 C CNN "Description"
F 7 "Yageo" H 3650 3550 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603FR-071K5L/729811" H 3650 3550 50  0001 C CNN "Website"
F 9 "311-1.50KHRCT-ND" H 3650 3550 50  0001 C CNN "Digi-Key_PN"
	1    3650 3550
	1    0    0    -1  
$EndComp
Text Notes 2750 3650 0    50   ~ 0
Vf = 1.8V, 2 mA Ityp\n5V-1.8 = 3.2V\n3.2V/1.5k = 2.1 mA
$Comp
L MyResistors:R_vert R303
U 1 1 5F7F7D78
P 5850 3600
F 0 "R303" H 5931 3712 50  0000 L CNN
F 1 "2.49k" H 5931 3621 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5905 3550 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 5850 3600 50  0001 C CNN
F 4 "0603" H 5931 3530 50  0000 L CNN "Package Size"
F 5 "RC0603FR-072K49L" H 5931 3439 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 2.49K OHM 1% 1/10W 0603" H 5850 3600 50  0001 C CNN "Description"
F 7 "Yageo" H 5850 3600 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/products/en?keywords=311-2.49KHRCT-ND" H 5850 3600 50  0001 C CNN "Website"
F 9 "311-2.49KHRCT-ND" H 5850 3600 50  0001 C CNN "Digi-Key_PN"
	1    5850 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3750 5850 3800
$Comp
L MyResistors:R_vert R304
U 1 1 5F7FA2C0
P 6850 3600
F 0 "R304" H 6931 3712 50  0000 L CNN
F 1 "10k" H 6931 3621 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6905 3550 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 6850 3600 50  0001 C CNN
F 4 "0603" H 6931 3530 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 6931 3439 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 6850 3600 50  0001 C CNN "Description"
F 7 "Yageo" H 6850 3600 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 6850 3600 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 6850 3600 50  0001 C CNN "Digi-Key_PN"
	1    6850 3600
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP301
U 1 1 5F7FAFD3
P 5850 3250
F 0 "JP301" V 5804 3318 50  0000 L CNN
F 1 "Solder Jumper" V 5895 3318 50  0000 L CNN
F 2 "" H 5850 3250 50  0001 C CNN
F 3 "~" H 5850 3250 50  0001 C CNN
	1    5850 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	5350 2250 5350 3250
Wire Wire Line
	6350 3050 6350 2250
$Comp
L MyCapacitors:CP1_Small_vert C302
U 1 1 5F813BB4
P 7000 2400
F 0 "C302" H 7091 2582 50  0000 L CNN
F 1 "10uF" H 7091 2491 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7000 2400 50  0001 C CNN
F 3 "https://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM21BR61C106KE15-01.pdf" H 7010 2470 50  0001 C CNN
F 4 "16V" H 7091 2400 50  0000 L CNN "Voltage Rating"
F 5 "0805" H 7091 2309 50  0000 L CNN "Package Size"
F 6 "GRM21BR61C106KE15L" H 7091 2218 50  0000 L CNN "MPN"
F 7 "490-3886-1-ND" H 7091 2309 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 7091 2218 50  0001 L CNN "Prefix"
F 9 "https://www.digikey.com/en/products/detail/murata-electronics/GRM21BR61C106KE15L/965928" H 7091 2127 50  0001 L CNN "Website"
F 10 "CAP CER 10UF 16V X5R 0805" H 7091 2036 50  0001 L CNN "Description"
F 11 "Murata Electronics" H 7091 1945 50  0001 L CNN "Manufacturer"
	1    7000 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3250 5350 3250
Wire Wire Line
	3650 1950 5750 1950
Wire Wire Line
	2250 1950 3650 1950
Wire Wire Line
	7100 1800 8600 1800
Wire Wire Line
	6150 2150 7000 2150
Wire Wire Line
	5850 3050 5850 3100
Wire Wire Line
	5850 3800 5850 3900
Connection ~ 5850 3800
Wire Wire Line
	5850 3450 5850 3400
$Comp
L MyCapacitors:CP1_Small_vert C301
U 1 1 5F8241B5
P 2250 2200
F 0 "C301" H 2341 2382 50  0000 L CNN
F 1 "10uF" H 2341 2291 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2250 2200 50  0001 C CNN
F 3 "https://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM21BR61C106KE15-01.pdf" H 2260 2270 50  0001 C CNN
F 4 "16V" H 2341 2200 50  0000 L CNN "Voltage Rating"
F 5 "0805" H 2341 2109 50  0000 L CNN "Package Size"
F 6 "GRM21BR61C106KE15L" H 2341 2018 50  0000 L CNN "MPN"
F 7 "490-3886-1-ND" H 2341 2109 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 2341 2018 50  0001 L CNN "Prefix"
F 9 "https://www.digikey.com/en/products/detail/murata-electronics/GRM21BR61C106KE15L/965928" H 2341 1927 50  0001 L CNN "Website"
F 10 "CAP CER 10UF 16V X5R 0805" H 2341 1836 50  0001 L CNN "Description"
F 11 "Murata Electronics" H 2341 1745 50  0001 L CNN "Manufacturer"
	1    2250 2200
	1    0    0    -1  
$EndComp
Text Notes 8150 1300 2    50   ~ 10
NEED TO FIND A GOOD SOCKET FOR THE SWITCH CABLE\nMIGHT JUST NOT POPULATE AND SOLDER DIRECT
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:S2B-PH-K-S_LF__SN_ J301
U 1 1 5F82D9D3
P 7100 1550
F 0 "J301" H 7012 1512 50  0000 R CNN
F 1 "Wire Switch Here" H 7012 1603 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x2_P2mm_Drill1mm_RA" H 7300 1750 60  0001 L CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 7300 1850 60  0001 L CNN
F 4 "455-1719-ND" H 7300 1950 60  0001 L CNN "Digi-Key_PN"
F 5 "S2B-PH-K-S(LF)(SN)" H 7300 2050 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 7300 2150 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 7300 2250 60  0001 L CNN "Family"
F 8 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 7300 2350 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/jst-sales-america-inc/S2B-PH-K-S(LF)(SN)/455-1719-ND/926626" H 7300 2450 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER R/A 2POS 2MM" H 7300 2550 60  0001 L CNN "Description"
F 11 "JST Sales America Inc." H 7300 2650 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7300 2750 60  0001 L CNN "Status"
	1    7100 1550
	-1   0    0    1   
$EndComp
Wire Wire Line
	7000 2150 8450 2150
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:S2B-PH-K-S_LF__SN_ J302
U 1 1 5F8290D6
P 8550 2150
F 0 "J302" V 8641 2022 50  0000 R CNN
F 1 "JST PH Battery Connector" V 8550 2022 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x2_P2mm_Drill1mm_RA" H 8750 2350 60  0001 L CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 8750 2450 60  0001 L CNN
F 4 "455-1719-ND" H 8750 2550 60  0001 L CNN "Digi-Key_PN"
F 5 "S2B-PH-K-S(LF)(SN)" H 8750 2650 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 8750 2750 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 8750 2850 60  0001 L CNN "Family"
F 8 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 8750 2950 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/jst-sales-america-inc/S2B-PH-K-S(LF)(SN)/455-1719-ND/926626" H 8750 3050 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER R/A 2POS 2MM" H 8750 3150 60  0001 L CNN "Description"
F 11 "JST Sales America Inc." H 8750 3250 60  0001 L CNN "Manufacturer"
F 12 "Active" H 8750 3350 60  0001 L CNN "Status"
	1    8550 2150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8300 2050 8450 2050
Wire Wire Line
	8300 2050 8300 2300
Text Notes 9200 2400 2    50   ~ 10
CHECK POLARITY
Text Notes 7800 3950 0    50   ~ 0
Open:    10k = 100 mA\nClosed:  2.0k = 500 mA\n\nBatt charging rate:\n\n10k = 100mA    *\n5.0k = 200 mA\n2.0k = 500 mA  *\n1.0k = 1000mA \n\nAdafruit typically does 0.5C for their batteries\n2500 mAh capacity - 1200 mA charge current
Wire Wire Line
	6850 3900 6850 3800
Wire Wire Line
	6400 3900 6850 3900
Wire Wire Line
	5850 3900 6400 3900
Connection ~ 6400 3900
Wire Wire Line
	5850 3050 6350 3050
Connection ~ 6350 3050
Wire Wire Line
	6850 3450 6850 3050
Wire Wire Line
	6350 3050 6850 3050
$EndSCHEMATC
