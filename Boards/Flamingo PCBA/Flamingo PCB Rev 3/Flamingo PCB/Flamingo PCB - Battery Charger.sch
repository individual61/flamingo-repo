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
Text Notes 600  7700 0    39   ~ 0
--------FLOW CHART--------\n\n###SHUTDOWN MODE\nVDD < VUVLO\nVDD < VBAT\nor\nPROG > 200 k\nSTAT = High Z\n\n###PRECONDITIONING \nCharge Current = IPREG\nSTAT = LOW\n\n###FAST CHARGE \nAlso get here if VBAT > VPTH from SHUTDOWN    \nor   \nVBAT < VRTH  from CHARGE COMPLETE\n\nCharge Current = IREG\nSTAT = LOW\n\n###CONSTANT VOLTAGE \nCharge Voltage = VREG\nSTAT = LOW\n\n###CHARGE MODE \nSTAT = HIGH (MCP73831)\nSTAT = High Z (MCP73832)\n\n--------PART NUMBER BREAKDOWN--------\n\nMCP73831T - 2 * * * _ OT\n\n(T) Tape and reel\n(2) 4.20 V regulated\n(OT) SMall Outline Transistor SOT23 T-Lead\n\n#######\n\nMCP73831T - 2 A C I _ OT\n(AT) Ipreg/Ireg = 10%\n        Iterm/Ireg = 7.5%\n\nMCP73831T - 2 A T I _ OT\n(AT) Ipreg/Ireg = 10%\n        Iterm/Ireg = 20%\n\nMCP73831T - 2 D C I _ OT\n(DC) Ipreg/Ireg = 100%\n        Iterm/Ireg = 7.5%
$Comp
L power:GND #PWR0304
U 1 1 5F7DD8CE
P 7100 2700
F 0 "#PWR0304" H 7100 2450 50  0001 C CNN
F 1 "GND" H 7105 2527 50  0000 C CNN
F 2 "" H 7100 2700 50  0001 C CNN
F 3 "" H 7100 2700 50  0001 C CNN
	1    7100 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0305
U 1 1 5F7E1F62
P 7700 4000
F 0 "#PWR0305" H 7700 3750 50  0001 C CNN
F 1 "GND" H 7705 3827 50  0000 C CNN
F 2 "" H 7700 4000 50  0001 C CNN
F 3 "" H 7700 4000 50  0001 C CNN
	1    7700 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0306
U 1 1 5F7E390B
P 8300 2600
F 0 "#PWR0306" H 8300 2350 50  0001 C CNN
F 1 "GND" H 8305 2427 50  0000 C CNN
F 2 "" H 8300 2600 50  0001 C CNN
F 3 "" H 8300 2600 50  0001 C CNN
	1    8300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2250 8300 2400
Connection ~ 8300 2250
$Comp
L power:GND #PWR0307
U 1 1 5F7E6098
P 9600 2400
F 0 "#PWR0307" H 9600 2150 50  0001 C CNN
F 1 "GND" H 9605 2227 50  0000 C CNN
F 2 "" H 9600 2400 50  0001 C CNN
F 3 "" H 9600 2400 50  0001 C CNN
	1    9600 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1750 8300 2250
Wire Wire Line
	8400 1750 8400 1900
Text HLabel 9900 1900 2    50   UnSpc ~ 10
V_BAT
Wire Wire Line
	7500 2450 7650 2450
$Comp
L power:GND #PWR0302
U 1 1 5F7ED2F5
P 3550 2900
F 0 "#PWR0302" H 3550 2650 50  0001 C CNN
F 1 "GND" H 3555 2727 50  0000 C CNN
F 2 "" H 3550 2900 50  0001 C CNN
F 3 "" H 3550 2900 50  0001 C CNN
	1    3550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4500 4950 4700
$Comp
L power:GND #PWR0303
U 1 1 5F7EC089
P 4950 4700
F 0 "#PWR0303" H 4950 4450 50  0001 C CNN
F 1 "GND" H 4955 4527 50  0000 C CNN
F 2 "" H 4950 4700 50  0001 C CNN
F 3 "" H 4950 4700 50  0001 C CNN
	1    4950 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4050 4950 4200
Wire Wire Line
	4950 2700 4950 2950
$Comp
L MyLEDs:LED_ALT_vert D301
U 1 1 5F7EA956
P 4950 2550
F 0 "D301" H 5068 2680 50  0000 L CNN
F 1 "Red/Charging" H 5068 2589 50  0000 L CNN
F 2 "LEDs:LED_0603_HandSoldering" H 5050 2550 50  0001 C CNN
F 3 "https://dammedia.osram.info/media/resource/hires/osram-dam-2493517/LS%20L29K.pdf" H 5150 2650 50  0001 C CNN
F 4 "0603" H 5068 2498 50  0000 L CNN "Package Size"
F 5 "LS L29K-G1J2-1-Z" H 5068 2407 50  0000 L CNN "MFR P/N"
F 6 "LED RED DIFFUSED 0603 SMD" H 4950 2550 50  0001 C CNN "Description"
F 7 "OSRAM Opto Semiconductors Inc." H 4950 2550 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/osram-opto-semiconductors-inc/LS-L29K-G1J2-1-Z/1802633" H 4950 2550 50  0001 C CNN "Website"
F 9 "475-2506-1-ND" H 4950 2550 50  0001 C CNN "Digi-Key_PN"
	1    4950 2550
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R301
U 1 1 5F7EA095
P 4950 3100
F 0 "R301" H 5031 3212 50  0000 L CNN
F 1 "1.5k" H 5031 3121 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5005 3050 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 4950 3100 50  0001 C CNN
F 4 "0603" H 5031 3030 50  0000 L CNN "Package Size"
F 5 "RC0603FR-071K5L" H 5031 2939 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 1.5K OHM 1% 1/10W 0603" H 4950 3100 50  0001 C CNN "Description"
F 7 "Yageo" H 4950 3100 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603FR-071K5L/729811" H 4950 3100 50  0001 C CNN "Website"
F 9 "311-1.50KHRCT-ND" H 4950 3100 50  0001 C CNN "Digi-Key_PN"
	1    4950 3100
	1    0    0    -1  
$EndComp
$Comp
L MyLEDs:LED_ALT_vert D302
U 1 1 5F7E8AF6
P 4950 4350
F 0 "D302" H 5067 4480 50  0000 L CNN
F 1 "Green/Done" H 5067 4389 50  0000 L CNN
F 2 "LEDs:LED_0603_HandSoldering" H 5050 4350 50  0001 C CNN
F 3 "https://dammedia.osram.info/media/resource/hires/osram-dam-2493945/LG%20L29K.pdf" H 5150 4450 50  0001 C CNN
F 4 "0603" H 5067 4298 50  0000 L CNN "Package Size"
F 5 "LG L29K-F2J1-24-Z" H 5067 4207 50  0000 L CNN "MFR P/N"
F 6 "LED GREEN DIFFUSED 0603 SMD" H 4950 4350 50  0001 C CNN "Description"
F 7 "OSRAM Opto Semiconductors Inc." H 4950 4350 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/osram-opto-semiconductors-inc/LG-L29K-F2J1-24-Z/2513791" H 4950 4350 50  0001 C CNN "Website"
F 9 "475-3118-1-ND" H 4950 4350 50  0001 C CNN "Digi-Key_PN"
	1    4950 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3300 4950 3550
Connection ~ 4950 3550
Wire Wire Line
	4950 3550 4950 3700
Text HLabel 2600 2250 0    50   UnSpc ~ 10
V_BUS
Wire Wire Line
	2600 2250 3000 2250
$Comp
L power:PWR_FLAG #FLG0301
U 1 1 5F839ABA
P 3000 2250
F 0 "#FLG0301" H 3000 2325 50  0001 C CNN
F 1 "PWR_FLAG" H 3000 2423 50  0000 C CNN
F 2 "" H 3000 2250 50  0001 C CNN
F 3 "~" H 3000 2250 50  0001 C CNN
	1    3000 2250
	1    0    0    -1  
$EndComp
Text Notes 4050 3250 0    50   ~ 0
Vf = 1.8V, 2 mA Ityp\n5V-1.8 = 3.2V\n3.2V/1.5k = 2.1 mA
Text Notes 5050 3500 0    50   ~ 0
HIGH when charging is done
Text Notes 350  -300 0    50   ~ 0
A search for 0603 OSRAM leds\n\nhttps://www.digikey.com/short/zwdccj\nBlue\nGreen\norange\nRed\nWhite\nWhite Cool\nYellow
$Comp
L MyResistors:R_vert R302
U 1 1 5F7F1D0C
P 4950 3850
F 0 "R302" H 5031 3962 50  0000 L CNN
F 1 "1.5k" H 5031 3871 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5005 3800 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 4950 3850 50  0001 C CNN
F 4 "0603" H 5031 3780 50  0000 L CNN "Package Size"
F 5 "RC0603FR-071K5L" H 5031 3689 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 1.5K OHM 1% 1/10W 0603" H 4950 3850 50  0001 C CNN "Description"
F 7 "Yageo" H 4950 3850 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.com/en/products/detail/yageo/RC0603FR-071K5L/729811" H 4950 3850 50  0001 C CNN "Website"
F 9 "311-1.50KHRCT-ND" H 4950 3850 50  0001 C CNN "Digi-Key_PN"
	1    4950 3850
	1    0    0    -1  
$EndComp
Text Notes 4050 3950 0    50   ~ 0
Vf = 1.8V, 2 mA Ityp\n5V-1.8 = 3.2V\n3.2V/1.5k = 2.1 mA
$Comp
L MyResistors:R_vert R303
U 1 1 5F7F7D78
P 7150 3700
F 0 "R303" H 7231 3812 50  0000 L CNN
F 1 "2.49k" H 7231 3721 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7205 3650 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 7150 3700 50  0001 C CNN
F 4 "0603" H 7231 3630 50  0000 L CNN "Package Size"
F 5 "RC0603FR-072K49L" H 7231 3539 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 2.49K OHM 1% 1/10W 0603" H 7150 3700 50  0001 C CNN "Description"
F 7 "Yageo" H 7150 3700 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/products/en?keywords=311-2.49KHRCT-ND" H 7150 3700 50  0001 C CNN "Website"
F 9 "311-2.49KHRCT-ND" H 7150 3700 50  0001 C CNN "Digi-Key_PN"
	1    7150 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3850 7150 3900
$Comp
L MyResistors:R_vert R304
U 1 1 5F7FA2C0
P 8150 3700
F 0 "R304" H 8231 3812 50  0000 L CNN
F 1 "10k" H 8231 3721 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8205 3650 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 8150 3700 50  0001 C CNN
F 4 "0603" H 8231 3630 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 8231 3539 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 8150 3700 50  0001 C CNN "Description"
F 7 "Yageo" H 8150 3700 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 8150 3700 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 8150 3700 50  0001 C CNN "Digi-Key_PN"
	1    8150 3700
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP301
U 1 1 5F7FAFD3
P 7150 3350
F 0 "JP301" V 7104 3418 50  0000 L CNN
F 1 "Solder Jumper" V 7195 3418 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 7150 3350 50  0001 C CNN
F 3 "~" H 7150 3350 50  0001 C CNN
	1    7150 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 3150 7650 2450
$Comp
L MyCapacitors:CP1_Small_vert C302
U 1 1 5F813BB4
P 8300 2500
F 0 "C302" H 8391 2682 50  0000 L CNN
F 1 "10uF" H 8391 2591 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8300 2500 50  0001 C CNN
F 3 "https://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM21BR61C106KE15-01.pdf" H 8310 2570 50  0001 C CNN
F 4 "16V" H 8391 2500 50  0000 L CNN "Voltage Rating"
F 5 "0805" H 8391 2409 50  0000 L CNN "Package Size"
F 6 "GRM21BR61C106KE15L" H 8391 2318 50  0000 L CNN "MPN"
F 7 "490-3886-1-ND" H 8391 2409 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 8391 2318 50  0001 L CNN "Prefix"
F 9 "https://www.digikey.com/en/products/detail/murata-electronics/GRM21BR61C106KE15L/965928" H 8391 2227 50  0001 L CNN "Website"
F 10 "CAP CER 10UF 16V X5R 0805" H 8391 2136 50  0001 L CNN "Description"
F 11 "Murata Electronics" H 8391 2045 50  0001 L CNN "Manufacturer"
	1    8300 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3550 6700 3550
Wire Wire Line
	8400 1900 9900 1900
Wire Wire Line
	7150 3150 7150 3200
Wire Wire Line
	7150 3900 7150 4000
Connection ~ 7150 3900
Wire Wire Line
	7150 3550 7150 3500
$Comp
L MyCapacitors:CP1_Small_vert C301
U 1 1 5F8241B5
P 3550 2650
F 0 "C301" H 3641 2832 50  0000 L CNN
F 1 "10uF" H 3641 2741 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3550 2650 50  0001 C CNN
F 3 "https://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM21BR61C106KE15-01.pdf" H 3560 2720 50  0001 C CNN
F 4 "16V" H 3641 2650 50  0000 L CNN "Voltage Rating"
F 5 "0805" H 3641 2559 50  0000 L CNN "Package Size"
F 6 "GRM21BR61C106KE15L" H 3641 2468 50  0000 L CNN "MPN"
F 7 "490-3886-1-ND" H 3641 2559 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 3641 2468 50  0001 L CNN "Prefix"
F 9 "https://www.digikey.com/en/products/detail/murata-electronics/GRM21BR61C106KE15L/965928" H 3641 2377 50  0001 L CNN "Website"
F 10 "CAP CER 10UF 16V X5R 0805" H 3641 2286 50  0001 L CNN "Description"
F 11 "Murata Electronics" H 3641 2195 50  0001 L CNN "Manufacturer"
	1    3550 2650
	1    0    0    -1  
$EndComp
Text Notes 7650 1400 0    50   ~ 10
TODO:\nNEED TO FIND A GOOD SOCKET FOR THE SWITCH CABLE\nMIGHT JUST NOT POPULATE AND SOLDER DIRECT
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:S2B-PH-K-S_LF__SN_ J302
U 1 1 5F82D9D3
P 8400 1650
F 0 "J302" H 8312 1612 50  0000 R CNN
F 1 "Wire Switch Here" H 8312 1703 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x2_P2mm_Drill1mm_RA" H 8600 1850 60  0001 L CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 8600 1950 60  0001 L CNN
F 4 "455-1719-ND" H 8600 2050 60  0001 L CNN "Digi-Key_PN"
F 5 "S2B-PH-K-S(LF)(SN)" H 8600 2150 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 8600 2250 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 8600 2350 60  0001 L CNN "Family"
F 8 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 8600 2450 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/jst-sales-america-inc/S2B-PH-K-S(LF)(SN)/455-1719-ND/926626" H 8600 2550 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER R/A 2POS 2MM" H 8600 2650 60  0001 L CNN "Description"
F 11 "JST Sales America Inc." H 8600 2750 60  0001 L CNN "Manufacturer"
F 12 "Active" H 8600 2850 60  0001 L CNN "Status"
	1    8400 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 2250 9750 2250
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:S2B-PH-K-S_LF__SN_ J303
U 1 1 5F8290D6
P 9850 2250
F 0 "J303" V 9941 2122 50  0000 R CNN
F 1 "JST PH Battery Connector" V 9850 2122 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x2_P2mm_Drill1mm_RA" H 10050 2450 60  0001 L CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 10050 2550 60  0001 L CNN
F 4 "455-1719-ND" H 10050 2650 60  0001 L CNN "Digi-Key_PN"
F 5 "S2B-PH-K-S(LF)(SN)" H 10050 2750 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 10050 2850 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 10050 2950 60  0001 L CNN "Family"
F 8 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 10050 3050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/jst-sales-america-inc/S2B-PH-K-S(LF)(SN)/455-1719-ND/926626" H 10050 3150 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER R/A 2POS 2MM" H 10050 3250 60  0001 L CNN "Description"
F 11 "JST Sales America Inc." H 10050 3350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 10050 3450 60  0001 L CNN "Status"
	1    9850 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9600 2150 9750 2150
Wire Wire Line
	9600 2150 9600 2400
Text Notes 9900 2600 0    50   ~ 10
TODO:\nCHECK POLARITY
Text Notes 9100 4050 0    50   ~ 0
Open:    10k = 100 mA\nClosed:  2.0k = 500 mA\n\nBatt charging rate:\n\n10k = 100mA    *\n5.0k = 200 mA\n2.0k = 500 mA  *\n1.0k = 1000mA \n\nAdafruit typically does 0.5C for their batteries\n2500 mAh capacity - 1200 mA charge current
Wire Wire Line
	8150 4000 8150 3900
Wire Wire Line
	7700 4000 8150 4000
Wire Wire Line
	7150 4000 7700 4000
Connection ~ 7700 4000
Wire Wire Line
	7150 3150 7650 3150
Connection ~ 7650 3150
Wire Wire Line
	8150 3550 8150 3150
Wire Wire Line
	7650 3150 8150 3150
$Comp
L dk_USB-DVI-HDMI-Connectors:10103594-0001LF J301
U 1 1 5F8008FC
P 1150 2750
F 0 "J301" H 1164 3473 50  0000 C CNN
F 1 "10103594-0001LF" H 1164 3382 50  0000 C CNN
F 2 "digikey-footprints:USB_Micro_B_Female_10103594-0001LF" H 1350 2950 60  0001 L CNN
F 3 "https://cdn.amphenol-icc.com/media/wysiwyg/files/drawing/10103594.pdf" H 1350 3050 60  0001 L CNN
F 4 "609-4050-1-ND" H 1350 3150 60  0001 L CNN "Digi-Key_PN"
F 5 "10103594-0001LF" H 1350 3250 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 1350 3350 60  0001 L CNN "Category"
F 7 "USB, DVI, HDMI Connectors" H 1350 3450 60  0001 L CNN "Family"
F 8 "https://cdn.amphenol-icc.com/media/wysiwyg/files/drawing/10103594.pdf" H 1350 3550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/amphenol-icc-fci/10103594-0001LF/609-4050-1-ND/2350357" H 1350 3650 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN RCPT USB2.0 MICRO B SMD R/A" H 1350 3750 60  0001 L CNN "Description"
F 11 "Amphenol ICC (FCI)" H 1350 3850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1350 3950 60  0001 L CNN "Status"
	1    1150 2750
	1    0    0    -1  
$EndComp
Text Notes 600  3750 0    50   Italic 0
10118194-0001LF would have been nicer, \nas it says 4 DIP legs, vis this SMT plus 2 DIP,\nbut was shipping like 3 months out when I made this
Wire Wire Line
	1400 2550 3000 2550
Wire Wire Line
	3000 2750 3000 2550
Connection ~ 3000 2250
$Comp
L power:GND #PWR0301
U 1 1 5F80F687
P 3000 3100
F 0 "#PWR0301" H 3000 2850 50  0001 C CNN
F 1 "GND" H 3005 2927 50  0000 C CNN
F 2 "" H 3000 3100 50  0001 C CNN
F 3 "" H 3000 3100 50  0001 C CNN
	1    3000 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2950 3000 3100
Text Notes 4350 6400 0    50   ~ 0
Will need to take some approach to negotiating higher power delivery if I am planning on using more than 500 mA. For example, a 2000 mAh LiPo charges at 1200 mA.\n\nApproaches are:\n\nDont.\nhttps://www.maximintegrated.com/en/design/technical-documents/tutorials/4/4803.html#3
$Comp
L power:PWR_FLAG #FLG0302
U 1 1 5F810FFE
P 3000 2950
F 0 "#FLG0302" H 3000 3025 50  0001 C CNN
F 1 "PWR_FLAG" H 3000 3123 50  0000 C CNN
F 2 "" H 3000 2950 50  0001 C CNN
F 3 "~" H 3000 2950 50  0001 C CNN
	1    3000 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2750 3550 2900
Connection ~ 3000 2950
Wire Wire Line
	1400 2950 1700 2950
Connection ~ 1700 2950
Wire Wire Line
	1700 2950 3000 2950
Wire Wire Line
	1700 3450 1000 3450
Wire Wire Line
	1000 3450 1000 3350
Wire Wire Line
	1700 2950 1700 3450
Text Notes 4200 1300 0    50   ~ 0
V_BUS comes from USB\n\nOn/Off switch controls V_BAT
$Comp
L MyICs:MCP73831T-2ATI_OT U301
U 1 1 5F91A003
P 7100 2250
F 0 "U301" H 6800 2750 60  0000 L CNN
F 1 "MCP73831T-2ATI_OT" H 6800 2650 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 8000 2500 60  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001984g.pdf" H 7300 2550 60  0001 L CNN
F 4 "MCP73831T-2ATI/OTCT-ND" H 8000 2700 60  0001 L CNN "Digi-Key_PN"
F 5 "MCP73831T-2ATI/OT" H 6800 2550 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 8000 2900 60  0001 L CNN "Category"
F 7 "PMIC - Battery Chargers" H 8000 3000 60  0001 L CNN "Family"
F 8 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001984g.pdf" H 8000 3100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/microchip-technology/MCP73831T-2ATI-OT/MCP73831T-2ATI-OTCT-ND/1979803" H 8000 3200 60  0001 L CNN "DK_Detail_Page"
F 10 "IC CONTROLLR LI-ION 4.2V SOT23-5" H 8000 3300 60  0001 L CNN "Description"
F 11 "Microchip Technology" H 8000 3400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 8000 3500 60  0001 L CNN "Status"
F 13 "4.20 V" H 6800 2450 50  0000 L CNN "Vreg"
	1    7100 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2250 8300 2250
Wire Wire Line
	7100 2700 7100 2650
Wire Wire Line
	6700 2450 6700 3550
Connection ~ 3000 2550
Wire Wire Line
	3000 2550 3000 2250
Connection ~ 3550 2550
Wire Wire Line
	3550 2550 3550 2750
Connection ~ 3550 2750
Wire Wire Line
	3000 2250 3550 2250
Wire Wire Line
	3550 2250 3550 2550
Connection ~ 3550 2250
Wire Wire Line
	3550 2250 4950 2250
Wire Wire Line
	4950 2400 4950 2250
Connection ~ 4950 2250
Wire Wire Line
	4950 2250 6700 2250
$EndSCHEMATC
