EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Button Remote For Flamingo PCB"
Date "2020-10-14"
Rev "3"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MyResistors:R_vert R?
U 1 1 5F87C0ED
P 2300 5200
AR Path="/5F780D75/5F87C0ED" Ref="R?"  Part="1" 
AR Path="/5F780A01/5F87C0ED" Ref="R?"  Part="1" 
AR Path="/5FA54816/5F87C0ED" Ref="R?"  Part="1" 
AR Path="/5F872CAB/5F87C0ED" Ref="R?"  Part="1" 
AR Path="/5F87C0ED" Ref="R?"  Part="1" 
F 0 "R?" H 2381 5312 50  0000 L CNN
F 1 "10k" H 2381 5221 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2355 5150 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 2300 5200 50  0001 C CNN
F 4 "0603" H 2381 5130 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 2381 5039 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 2300 5200 50  0001 C CNN "Description"
F 7 "Yageo" H 2300 5200 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 2300 5200 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 2300 5200 50  0001 C CNN "Digi-Key_PN"
	1    2300 5200
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S?
U 1 1 5F87C0F8
P 2200 5800
AR Path="/5F780A01/5F87C0F8" Ref="S?"  Part="1" 
AR Path="/5FA54816/5F87C0F8" Ref="S?"  Part="1" 
AR Path="/5F872CAB/5F87C0F8" Ref="S?"  Part="1" 
AR Path="/5F87C0F8" Ref="S?"  Part="1" 
F 0 "S?" H 2344 5891 50  0000 L BNN
F 1 "10-XX_vert" H 2344 5800 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 2343 5755 50  0001 L CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 2200 5800 60  0001 C CNN
F 4 "B3F-1000" H 2344 5709 50  0000 L CNN "MPN"
F 5 "S" H 2343 5755 50  0001 L CNN "Prefix"
F 6 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150" H 2343 5664 50  0001 L CNN "Website"
F 7 "SWITCH TACTILE SPST-NO 0.05A 24V" H 2343 5573 50  0001 L CNN "Description"
F 8 "Omron Electronics Inc-EMC Div" H 2343 5482 50  0001 L CNN "Manufacturer"
	1    2200 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6000 2300 6000
Wire Wire Line
	2200 5600 2300 5600
Connection ~ 2300 5600
$Comp
L power:GND #PWR?
U 1 1 5F87C101
P 2300 6050
AR Path="/5F780A01/5F87C101" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5F87C101" Ref="#PWR?"  Part="1" 
AR Path="/5F872CAB/5F87C101" Ref="#PWR?"  Part="1" 
AR Path="/5F87C101" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2300 5800 50  0001 C CNN
F 1 "GND" H 2300 5900 50  0000 C CNN
F 2 "" H 2300 6050 50  0001 C CNN
F 3 "" H 2300 6050 50  0001 C CNN
	1    2300 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 6000 2300 6050
Connection ~ 2300 6000
Wire Wire Line
	2300 5000 2300 5050
Text Label 2050 5500 2    50   ~ 10
Button_1
Wire Wire Line
	2300 5400 2300 5500
Wire Wire Line
	2050 5500 2300 5500
Connection ~ 2300 5500
Wire Wire Line
	2300 5500 2300 5600
$Comp
L MyResistors:R_vert R?
U 1 1 5F87C11B
P 4350 5200
AR Path="/5F780D75/5F87C11B" Ref="R?"  Part="1" 
AR Path="/5F780A01/5F87C11B" Ref="R?"  Part="1" 
AR Path="/5FA54816/5F87C11B" Ref="R?"  Part="1" 
AR Path="/5F872CAB/5F87C11B" Ref="R?"  Part="1" 
AR Path="/5F87C11B" Ref="R?"  Part="1" 
F 0 "R?" H 4431 5312 50  0000 L CNN
F 1 "10k" H 4431 5221 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4405 5150 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 4350 5200 50  0001 C CNN
F 4 "0603" H 4431 5130 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 4431 5039 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 4350 5200 50  0001 C CNN "Description"
F 7 "Yageo" H 4350 5200 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 4350 5200 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 4350 5200 50  0001 C CNN "Digi-Key_PN"
	1    4350 5200
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S?
U 1 1 5F87C126
P 4250 5800
AR Path="/5F780A01/5F87C126" Ref="S?"  Part="1" 
AR Path="/5FA54816/5F87C126" Ref="S?"  Part="1" 
AR Path="/5F872CAB/5F87C126" Ref="S?"  Part="1" 
AR Path="/5F87C126" Ref="S?"  Part="1" 
F 0 "S?" H 4394 5891 50  0000 L BNN
F 1 "10-XX_vert" H 4394 5800 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 4393 5755 50  0001 L CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 4250 5800 60  0001 C CNN
F 4 "B3F-1000" H 4394 5709 50  0000 L CNN "MPN"
F 5 "S" H 4393 5755 50  0001 L CNN "Prefix"
F 6 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150" H 4393 5664 50  0001 L CNN "Website"
F 7 "SWITCH TACTILE SPST-NO 0.05A 24V" H 4393 5573 50  0001 L CNN "Description"
F 8 "Omron Electronics Inc-EMC Div" H 4393 5482 50  0001 L CNN "Manufacturer"
	1    4250 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6000 4350 6000
Wire Wire Line
	4250 5600 4350 5600
Connection ~ 4350 5600
$Comp
L power:GND #PWR?
U 1 1 5F87C12F
P 4350 6050
AR Path="/5F780A01/5F87C12F" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5F87C12F" Ref="#PWR?"  Part="1" 
AR Path="/5F872CAB/5F87C12F" Ref="#PWR?"  Part="1" 
AR Path="/5F87C12F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4350 5800 50  0001 C CNN
F 1 "GND" H 4350 5900 50  0000 C CNN
F 2 "" H 4350 6050 50  0001 C CNN
F 3 "" H 4350 6050 50  0001 C CNN
	1    4350 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 6000 4350 6050
Connection ~ 4350 6000
Wire Wire Line
	4350 5000 4350 5050
Text Label 4100 5500 2    50   ~ 10
Button_2
Wire Wire Line
	4350 5400 4350 5500
Wire Wire Line
	4100 5500 4350 5500
Connection ~ 4350 5500
Wire Wire Line
	4350 5500 4350 5600
$Comp
L MyResistors:R_vert R?
U 1 1 5F87C149
P 6200 5200
AR Path="/5F780D75/5F87C149" Ref="R?"  Part="1" 
AR Path="/5F780A01/5F87C149" Ref="R?"  Part="1" 
AR Path="/5FA54816/5F87C149" Ref="R?"  Part="1" 
AR Path="/5F872CAB/5F87C149" Ref="R?"  Part="1" 
AR Path="/5F87C149" Ref="R?"  Part="1" 
F 0 "R?" H 6281 5312 50  0000 L CNN
F 1 "10k" H 6281 5221 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6255 5150 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_11.pdf" H 6200 5200 50  0001 C CNN
F 4 "0603" H 6281 5130 50  0000 L CNN "Package Size"
F 5 "RC0603FR-0710KL" H 6281 5039 50  0000 L CNN "MFR P/N"
F 6 "RES SMD 10K OHM 1% 1/10W 0603" H 6200 5200 50  0001 C CNN "Description"
F 7 "Yageo" H 6200 5200 50  0001 C CNN "Manufacturer"
F 8 "https://www.digikey.sg/product-detail/en/yageo/RC0603FR-0710KL/311-10-0KHRCT-ND/729827" H 6200 5200 50  0001 C CNN "Website"
F 9 "311-10.0KHRCT-ND" H 6200 5200 50  0001 C CNN "Digi-Key_PN"
	1    6200 5200
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S?
U 1 1 5F87C154
P 6100 5800
AR Path="/5F780A01/5F87C154" Ref="S?"  Part="1" 
AR Path="/5FA54816/5F87C154" Ref="S?"  Part="1" 
AR Path="/5F872CAB/5F87C154" Ref="S?"  Part="1" 
AR Path="/5F87C154" Ref="S?"  Part="1" 
F 0 "S?" H 6244 5891 50  0000 L BNN
F 1 "10-XX_vert" H 6244 5800 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 6243 5755 50  0001 L CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 6100 5800 60  0001 C CNN
F 4 "B3F-1000" H 6244 5709 50  0000 L CNN "MPN"
F 5 "S" H 6243 5755 50  0001 L CNN "Prefix"
F 6 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150" H 6243 5664 50  0001 L CNN "Website"
F 7 "SWITCH TACTILE SPST-NO 0.05A 24V" H 6243 5573 50  0001 L CNN "Description"
F 8 "Omron Electronics Inc-EMC Div" H 6243 5482 50  0001 L CNN "Manufacturer"
	1    6100 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 6000 6200 6000
Wire Wire Line
	6100 5600 6200 5600
Connection ~ 6200 5600
$Comp
L power:GND #PWR?
U 1 1 5F87C15D
P 6200 6050
AR Path="/5F780A01/5F87C15D" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5F87C15D" Ref="#PWR?"  Part="1" 
AR Path="/5F872CAB/5F87C15D" Ref="#PWR?"  Part="1" 
AR Path="/5F87C15D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6200 5800 50  0001 C CNN
F 1 "GND" H 6200 5900 50  0000 C CNN
F 2 "" H 6200 6050 50  0001 C CNN
F 3 "" H 6200 6050 50  0001 C CNN
	1    6200 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 6000 6200 6050
Connection ~ 6200 6000
Wire Wire Line
	6200 5000 6200 5050
Text Label 5950 5500 2    50   ~ 10
Button_3
Wire Wire Line
	6200 5400 6200 5500
Wire Wire Line
	5950 5500 6200 5500
Connection ~ 6200 5500
Wire Wire Line
	6200 5500 6200 5600
$Comp
L Connector_Generic:Conn_01x06 J?
U 1 1 5F87CE2A
P 2500 2700
F 0 "J?" H 2418 2175 50  0000 C CNN
F 1 "Button Board Connector" H 2418 2266 50  0000 C CNN
F 2 "" H 2500 2700 50  0001 C CNN
F 3 "~" H 2500 2700 50  0001 C CNN
	1    2500 2700
	-1   0    0    1   
$EndComp
Text Label 2700 2400 0    50   ~ 10
PWR_SW_OUT
Text Label 2700 2900 0    50   ~ 10
PWR_SW_IN
Text Label 2700 2600 0    50   ~ 10
Button_2
Text Label 2700 2700 0    50   ~ 10
Button_3
Text Label 2700 2500 0    50   ~ 10
Button_1
$Comp
L power:GND #PWR?
U 1 1 5F8946F4
P 2700 2800
AR Path="/5F780A01/5F8946F4" Ref="#PWR?"  Part="1" 
AR Path="/5FA54816/5F8946F4" Ref="#PWR?"  Part="1" 
AR Path="/5F872CAB/5F8946F4" Ref="#PWR?"  Part="1" 
AR Path="/5F8946F4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2700 2550 50  0001 C CNN
F 1 "GND" H 2700 2650 50  0000 C CNN
F 2 "" H 2700 2800 50  0001 C CNN
F 3 "" H 2700 2800 50  0001 C CNN
	1    2700 2800
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 5F896A43
P 4650 2600
F 0 "SW?" H 4650 2835 50  0000 C CNN
F 1 "SW_SPST" H 4650 2744 50  0000 C CNN
F 2 "" H 4650 2600 50  0001 C CNN
F 3 "~" H 4650 2600 50  0001 C CNN
	1    4650 2600
	1    0    0    -1  
$EndComp
Text Label 4850 2600 0    50   ~ 10
PWR_SW_OUT
Text Label 4450 2600 2    50   ~ 10
PWR_SW_IN
Text Label 2300 5000 2    50   ~ 10
PWR_SW_OUT
Text Label 4350 5000 2    50   ~ 10
PWR_SW_OUT
Text Label 6200 5000 2    50   ~ 10
PWR_SW_OUT
Text Notes 3200 2900 0    50   ~ 10
This one is powered
$EndSCHEMATC
