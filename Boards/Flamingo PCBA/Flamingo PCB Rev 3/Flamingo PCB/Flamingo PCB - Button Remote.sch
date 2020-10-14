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
$Comp
L MyResistors:R_vert R?
U 1 1 5FA56864
P 2800 1950
AR Path="/5F780D75/5FA56864" Ref="R?"  Part="1" 
AR Path="/5F780A01/5FA56864" Ref="R?"  Part="1" 
AR Path="/5FA54816/5FA56864" Ref="R?"  Part="1" 
F 0 "R?" H 2881 2062 50  0000 L CNN
F 1 "10k" H 2881 1971 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2855 1900 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 2800 1950 50  0001 C CNN
F 4 "0603" H 2881 1880 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 2881 1789 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 2800 1950 50  0001 C CNN "Description"
F 7 "Yageo" H 2800 1950 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 2800 1950 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 2800 1950 50  0001 C CNN "Digi-Key_PN"
	1    2800 1950
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S?
U 1 1 5FA5686F
P 2700 2550
AR Path="/5F780A01/5FA5686F" Ref="S?"  Part="1" 
AR Path="/5FA54816/5FA5686F" Ref="S?"  Part="1" 
F 0 "S?" H 2844 2641 50  0000 L BNN
F 1 "10-XX_vert" H 2844 2550 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 2843 2505 50  0001 L CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 2700 2550 60  0001 C CNN
F 4 "B3F-1000" H 2844 2459 50  0000 L CNN "MPN"
F 5 "S" H 2843 2505 50  0001 L CNN "Prefix"
F 6 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150" H 2843 2414 50  0001 L CNN "Website"
F 7 "SWITCH TACTILE SPST-NO 0.05A 24V" H 2843 2323 50  0001 L CNN "Description"
F 8 "Omron Electronics Inc-EMC Div" H 2843 2232 50  0001 L CNN "Manufacturer"
	1    2700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 2750 2800 2750
Wire Wire Line
	2700 2350 2800 2350
Connection ~ 2800 2350
$Comp
L power:GND #PWR?
U 1 1 5FA56878
P 2800 2800
AR Path="/5F780A01/5FA56878" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5FA56878" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2800 2550 50  0001 C CNN
F 1 "GND" H 2800 2650 50  0000 C CNN
F 2 "" H 2800 2800 50  0001 C CNN
F 3 "" H 2800 2800 50  0001 C CNN
	1    2800 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 2750 2800 2800
Connection ~ 2800 2750
$Comp
L power:+5V #PWR?
U 1 1 5FA56880
P 2800 1750
AR Path="/5F780A01/5FA56880" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5FA56880" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2800 1600 50  0001 C CNN
F 1 "+5V" H 2800 1890 50  0000 C CNN
F 2 "" H 2800 1750 50  0001 C CNN
F 3 "" H 2800 1750 50  0001 C CNN
	1    2800 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 1750 2800 1800
Text Label 2550 2250 2    50   ~ 10
Button_1
Wire Wire Line
	2800 2150 2800 2250
Wire Wire Line
	2550 2250 2800 2250
Connection ~ 2800 2250
Wire Wire Line
	2800 2250 2800 2350
$Comp
L MyResistors:R_vert R?
U 1 1 5FA56892
P 4800 2000
AR Path="/5F780D75/5FA56892" Ref="R?"  Part="1" 
AR Path="/5F780A01/5FA56892" Ref="R?"  Part="1" 
AR Path="/5FA54816/5FA56892" Ref="R?"  Part="1" 
F 0 "R?" H 4881 2112 50  0000 L CNN
F 1 "10k" H 4881 2021 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4855 1950 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 4800 2000 50  0001 C CNN
F 4 "0603" H 4881 1930 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 4881 1839 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 4800 2000 50  0001 C CNN "Description"
F 7 "Yageo" H 4800 2000 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 4800 2000 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 4800 2000 50  0001 C CNN "Digi-Key_PN"
	1    4800 2000
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S?
U 1 1 5FA5689D
P 4700 2600
AR Path="/5F780A01/5FA5689D" Ref="S?"  Part="1" 
AR Path="/5FA54816/5FA5689D" Ref="S?"  Part="1" 
F 0 "S?" H 4844 2691 50  0000 L BNN
F 1 "10-XX_vert" H 4844 2600 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 4843 2555 50  0001 L CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 4700 2600 60  0001 C CNN
F 4 "B3F-1000" H 4844 2509 50  0000 L CNN "MPN"
F 5 "S" H 4843 2555 50  0001 L CNN "Prefix"
F 6 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150" H 4843 2464 50  0001 L CNN "Website"
F 7 "SWITCH TACTILE SPST-NO 0.05A 24V" H 4843 2373 50  0001 L CNN "Description"
F 8 "Omron Electronics Inc-EMC Div" H 4843 2282 50  0001 L CNN "Manufacturer"
	1    4700 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2800 4800 2800
Wire Wire Line
	4700 2400 4800 2400
Connection ~ 4800 2400
$Comp
L power:GND #PWR?
U 1 1 5FA568A6
P 4800 2850
AR Path="/5F780A01/5FA568A6" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5FA568A6" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4800 2600 50  0001 C CNN
F 1 "GND" H 4800 2700 50  0000 C CNN
F 2 "" H 4800 2850 50  0001 C CNN
F 3 "" H 4800 2850 50  0001 C CNN
	1    4800 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2800 4800 2850
Connection ~ 4800 2800
$Comp
L power:+5V #PWR?
U 1 1 5FA568AE
P 4800 1800
AR Path="/5F780A01/5FA568AE" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5FA568AE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4800 1650 50  0001 C CNN
F 1 "+5V" H 4800 1940 50  0000 C CNN
F 2 "" H 4800 1800 50  0001 C CNN
F 3 "" H 4800 1800 50  0001 C CNN
	1    4800 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1800 4800 1850
Text Label 4550 2300 2    50   ~ 10
Button_2
Wire Wire Line
	4800 2200 4800 2300
Wire Wire Line
	4550 2300 4800 2300
Connection ~ 4800 2300
Wire Wire Line
	4800 2300 4800 2400
$Comp
L MyResistors:R_vert R?
U 1 1 5FA98596
P 7150 2000
AR Path="/5F780D75/5FA98596" Ref="R?"  Part="1" 
AR Path="/5F780A01/5FA98596" Ref="R?"  Part="1" 
AR Path="/5FA54816/5FA98596" Ref="R?"  Part="1" 
F 0 "R?" H 7231 2112 50  0000 L CNN
F 1 "10k" H 7231 2021 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7205 1950 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 7150 2000 50  0001 C CNN
F 4 "0603" H 7231 1930 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 7231 1839 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 7150 2000 50  0001 C CNN "Description"
F 7 "Yageo" H 7150 2000 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 7150 2000 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 7150 2000 50  0001 C CNN "Digi-Key_PN"
	1    7150 2000
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S?
U 1 1 5FA985A1
P 7050 2600
AR Path="/5F780A01/5FA985A1" Ref="S?"  Part="1" 
AR Path="/5FA54816/5FA985A1" Ref="S?"  Part="1" 
F 0 "S?" H 7194 2691 50  0000 L BNN
F 1 "10-XX_vert" H 7194 2600 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 7193 2555 50  0001 L CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 7050 2600 60  0001 C CNN
F 4 "B3F-1000" H 7194 2509 50  0000 L CNN "MPN"
F 5 "S" H 7193 2555 50  0001 L CNN "Prefix"
F 6 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150" H 7193 2464 50  0001 L CNN "Website"
F 7 "SWITCH TACTILE SPST-NO 0.05A 24V" H 7193 2373 50  0001 L CNN "Description"
F 8 "Omron Electronics Inc-EMC Div" H 7193 2282 50  0001 L CNN "Manufacturer"
	1    7050 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2800 7150 2800
Wire Wire Line
	7050 2400 7150 2400
Connection ~ 7150 2400
$Comp
L power:GND #PWR?
U 1 1 5FA985AA
P 7150 2850
AR Path="/5F780A01/5FA985AA" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5FA985AA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7150 2600 50  0001 C CNN
F 1 "GND" H 7150 2700 50  0000 C CNN
F 2 "" H 7150 2850 50  0001 C CNN
F 3 "" H 7150 2850 50  0001 C CNN
	1    7150 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 2800 7150 2850
Connection ~ 7150 2800
$Comp
L power:+5V #PWR?
U 1 1 5FA985B2
P 7150 1800
AR Path="/5F780A01/5FA985B2" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5FA985B2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7150 1650 50  0001 C CNN
F 1 "+5V" H 7150 1940 50  0000 C CNN
F 2 "" H 7150 1800 50  0001 C CNN
F 3 "" H 7150 1800 50  0001 C CNN
	1    7150 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 1800 7150 1850
Text Label 6900 2300 2    50   ~ 10
Button_3
Wire Wire Line
	7150 2200 7150 2300
Wire Wire Line
	6900 2300 7150 2300
Connection ~ 7150 2300
Wire Wire Line
	7150 2300 7150 2400
Text Notes 3750 1250 0    50   ~ 10
This might have to be its own project
$EndSCHEMATC
