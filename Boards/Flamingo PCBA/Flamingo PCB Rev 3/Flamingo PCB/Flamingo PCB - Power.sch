EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
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
L MyCapacitors:C_Small_vert C?
U 1 1 5F90528B
P 6800 3700
F 0 "C?" H 6892 3832 50  0000 L CNN
F 1 "10uF" H 6892 3741 50  0000 L CNN
F 2 "" H 6800 3675 50  0001 L CNN
F 3 "" H 6900 3775 50  0001 L CNN
F 4 "XXXX" H 6892 3650 50  0000 L CNN "Package Size"
F 5 "Voltage" H 6892 3559 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 6892 3468 50  0000 L CNN "MPN"
F 7 "-" H 6900 3400 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 6900 3400 50  0001 L CNN "Prefix"
F 9 "-" H 6900 3400 50  0001 L CNN "Website"
F 10 "-" H 6900 3400 50  0001 L CNN "Description"
F 11 "-" H 6900 3400 50  0001 L CNN "Manufacturer"
	1    6800 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F906D29
P 6800 4000
F 0 "#PWR?" H 6800 3750 50  0001 C CNN
F 1 "GND" H 6805 3827 50  0000 C CNN
F 2 "" H 6800 4000 50  0001 C CNN
F 3 "" H 6800 4000 50  0001 C CNN
	1    6800 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3850 6800 4000
Text HLabel 9950 800  0    50   UnSpc ~ 0
V_BUS
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D?
U 1 1 5F909D28
P 10150 1150
F 0 "D?" V 10390 1072 50  0000 R CNN
F 1 "Schottky" V 10299 1072 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 10350 1350 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 10350 1450 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 10350 1550 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 10200 1072 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 10350 1750 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 10350 1850 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 10350 1950 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 10350 2050 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 10350 2150 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 10350 2250 60  0001 L CNN "Manufacturer"
F 12 "Active" H 10350 2350 60  0001 L CNN "Status"
F 13 "SOD-123" V 10102 1072 50  0000 R CNN "Package"
F 14 "0.45 V" V 10011 1072 50  0000 R CNN "Vf"
	1    10150 1150
	0    -1   -1   0   
$EndComp
$Comp
L MyICs:3.3V_Reg U?
U 1 1 5F80149D
P 8300 3550
F 0 "U?" H 7750 4150 60  0000 L CNN
F 1 "3.3V_Reg" H 7750 4050 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 9500 4100 60  0001 L CNN
F 3 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 8500 3850 60  0001 L CNN
F 4 "296-18476-1-ND" H 9500 4300 60  0001 L CNN "Digi-Key_PN"
F 5 "LP2985-33DBVR" H 7750 3950 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 9500 4500 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 9500 4600 60  0001 L CNN "Family"
F 8 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 9500 4700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/texas-instruments/LP2985-33DBVR/296-18476-1-ND/809911" H 9500 4800 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 3.3V 150MA SOT23-5" H 9500 4900 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 9500 5000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9500 5100 60  0001 L CNN "Status"
F 13 "150 mA" H 7750 3850 50  0000 L CNN "Imax"
	1    8300 3550
	1    0    0    -1  
$EndComp
Text HLabel 9350 3450 2    50   UnSpc ~ 0
+3.3V
Wire Wire Line
	9350 3450 9150 3450
Wire Wire Line
	9150 3450 8700 3450
NoConn ~ 8700 3650
$Comp
L MyCapacitors:C_Small_vert C?
U 1 1 5F803AE8
P 9150 3700
F 0 "C?" H 9242 3832 50  0000 L CNN
F 1 "10uF" H 9242 3741 50  0000 L CNN
F 2 "" H 9150 3675 50  0001 L CNN
F 3 "" H 9250 3775 50  0001 L CNN
F 4 "XXXX" H 9242 3650 50  0000 L CNN "Package Size"
F 5 "Voltage" H 9242 3559 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 9242 3468 50  0000 L CNN "MPN"
F 7 "-" H 9250 3400 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 9250 3400 50  0001 L CNN "Prefix"
F 9 "-" H 9250 3400 50  0001 L CNN "Website"
F 10 "-" H 9250 3400 50  0001 L CNN "Description"
F 11 "-" H 9250 3400 50  0001 L CNN "Manufacturer"
	1    9150 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F804804
P 9150 4000
F 0 "#PWR?" H 9150 3750 50  0001 C CNN
F 1 "GND" H 9155 3827 50  0000 C CNN
F 2 "" H 9150 4000 50  0001 C CNN
F 3 "" H 9150 4000 50  0001 C CNN
	1    9150 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F80525C
P 8200 4000
F 0 "#PWR?" H 8200 3750 50  0001 C CNN
F 1 "GND" H 8205 3827 50  0000 C CNN
F 2 "" H 8200 4000 50  0001 C CNN
F 3 "" H 8200 4000 50  0001 C CNN
	1    8200 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4000 8200 3850
Wire Wire Line
	7650 3650 7550 3650
Wire Wire Line
	7550 3650 7550 3450
Wire Wire Line
	7550 3450 7650 3450
Wire Wire Line
	6800 3450 6800 3650
Wire Wire Line
	6800 3450 7550 3450
Connection ~ 7550 3450
$Comp
L MyCapacitors:C_Small_vert C?
U 1 1 5F81B87E
P 6800 1650
F 0 "C?" H 6892 1782 50  0000 L CNN
F 1 "10uF" H 6892 1691 50  0000 L CNN
F 2 "" H 6800 1625 50  0001 L CNN
F 3 "" H 6900 1725 50  0001 L CNN
F 4 "XXXX" H 6892 1600 50  0000 L CNN "Package Size"
F 5 "Voltage" H 6892 1509 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 6892 1418 50  0000 L CNN "MPN"
F 7 "-" H 6900 1350 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 6900 1350 50  0001 L CNN "Prefix"
F 9 "-" H 6900 1350 50  0001 L CNN "Website"
F 10 "-" H 6900 1350 50  0001 L CNN "Description"
F 11 "-" H 6900 1350 50  0001 L CNN "Manufacturer"
	1    6800 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F81B884
P 6800 1950
F 0 "#PWR?" H 6800 1700 50  0001 C CNN
F 1 "GND" H 6805 1777 50  0000 C CNN
F 2 "" H 6800 1950 50  0001 C CNN
F 3 "" H 6800 1950 50  0001 C CNN
	1    6800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1800 6800 1950
$Comp
L MyICs:3.3V_Reg U?
U 1 1 5F81B895
P 8300 1500
F 0 "U?" H 7750 2100 60  0000 L CNN
F 1 "5V_Reg" H 7750 2000 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 9500 2050 60  0001 L CNN
F 3 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 8500 1800 60  0001 L CNN
F 4 "296-20717-1-ND" H 9500 2250 60  0001 L CNN "Digi-Key_PN"
F 5 "LP2985-50DBVR" H 7750 1900 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 9500 2450 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 9500 2550 60  0001 L CNN "Family"
F 8 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 9500 2650 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/products/detail/texas-instruments/LP2985-50DBVR/1169351" H 9500 2750 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 5V 150MA SOT23-5" H 9500 2850 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 9500 2950 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9500 3050 60  0001 L CNN "Status"
F 13 "150 mA" H 7750 1800 50  0000 L CNN "Imax"
	1    8300 1500
	1    0    0    -1  
$EndComp
Text HLabel 10450 1400 2    50   UnSpc ~ 0
+5V
NoConn ~ 8700 1600
$Comp
L MyCapacitors:C_Small_vert C?
U 1 1 5F81B8A8
P 10150 1650
F 0 "C?" H 10242 1782 50  0000 L CNN
F 1 "10uF" H 10242 1691 50  0000 L CNN
F 2 "" H 10150 1625 50  0001 L CNN
F 3 "" H 10250 1725 50  0001 L CNN
F 4 "XXXX" H 10242 1600 50  0000 L CNN "Package Size"
F 5 "Voltage" H 10242 1509 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 10242 1418 50  0000 L CNN "MPN"
F 7 "-" H 10250 1350 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 10250 1350 50  0001 L CNN "Prefix"
F 9 "-" H 10250 1350 50  0001 L CNN "Website"
F 10 "-" H 10250 1350 50  0001 L CNN "Description"
F 11 "-" H 10250 1350 50  0001 L CNN "Manufacturer"
	1    10150 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F81B8AF
P 10150 1950
F 0 "#PWR?" H 10150 1700 50  0001 C CNN
F 1 "GND" H 10155 1777 50  0000 C CNN
F 2 "" H 10150 1950 50  0001 C CNN
F 3 "" H 10150 1950 50  0001 C CNN
	1    10150 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F81B8B5
P 8200 1950
F 0 "#PWR?" H 8200 1700 50  0001 C CNN
F 1 "GND" H 8205 1777 50  0000 C CNN
F 2 "" H 8200 1950 50  0001 C CNN
F 3 "" H 8200 1950 50  0001 C CNN
	1    8200 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1950 8200 1800
Wire Wire Line
	7650 1600 7550 1600
Wire Wire Line
	7550 1600 7550 1400
Wire Wire Line
	7550 1400 7650 1400
Wire Wire Line
	6800 1400 6800 1600
Wire Wire Line
	6250 1400 6800 1400
Wire Wire Line
	6800 1400 7550 1400
Connection ~ 6800 1400
Connection ~ 7550 1400
Wire Wire Line
	10150 1950 10150 1800
Wire Wire Line
	10150 1600 10150 1400
Wire Wire Line
	9150 4000 9150 3850
$Comp
L MyCapacitors:C_Small_vert C?
U 1 1 5F82A2E6
P 6900 5700
F 0 "C?" H 6992 5832 50  0000 L CNN
F 1 "10uF" H 6992 5741 50  0000 L CNN
F 2 "" H 6900 5675 50  0001 L CNN
F 3 "" H 7000 5775 50  0001 L CNN
F 4 "XXXX" H 6992 5650 50  0000 L CNN "Package Size"
F 5 "Voltage" H 6992 5559 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 6992 5468 50  0000 L CNN "MPN"
F 7 "-" H 7000 5400 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 7000 5400 50  0001 L CNN "Prefix"
F 9 "-" H 7000 5400 50  0001 L CNN "Website"
F 10 "-" H 7000 5400 50  0001 L CNN "Description"
F 11 "-" H 7000 5400 50  0001 L CNN "Manufacturer"
	1    6900 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F82A2EC
P 6900 6000
F 0 "#PWR?" H 6900 5750 50  0001 C CNN
F 1 "GND" H 6905 5827 50  0000 C CNN
F 2 "" H 6900 6000 50  0001 C CNN
F 3 "" H 6900 6000 50  0001 C CNN
	1    6900 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 5850 6900 6000
$Comp
L MyICs:3.3V_Reg U?
U 1 1 5F82A2FD
P 8400 5550
F 0 "U?" H 7850 6150 60  0000 L CNN
F 1 "1.8V_Reg" H 7850 6050 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 9600 6100 60  0001 L CNN
F 3 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 8600 5850 60  0001 L CNN
F 4 "296-18474-1-ND" H 9600 6300 60  0001 L CNN "Digi-Key_PN"
F 5 "LP2985-18DBVR" H 7850 5950 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 9600 6500 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 9600 6600 60  0001 L CNN "Family"
F 8 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 9600 6700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/products/detail/texas-instruments/LP2985-18DBVR/809757" H 9600 6800 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 1.8V 150MA SOT23-5" H 9600 6900 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 9600 7000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9600 7100 60  0001 L CNN "Status"
F 13 "150 mA" H 7850 5850 50  0000 L CNN "Imax"
	1    8400 5550
	1    0    0    -1  
$EndComp
Text HLabel 9450 5450 2    50   UnSpc ~ 0
+1.8V
Wire Wire Line
	9450 5450 9250 5450
Wire Wire Line
	9250 5450 8800 5450
NoConn ~ 8800 5650
$Comp
L MyCapacitors:C_Small_vert C?
U 1 1 5F82A310
P 9250 5700
F 0 "C?" H 9342 5832 50  0000 L CNN
F 1 "10uF" H 9342 5741 50  0000 L CNN
F 2 "" H 9250 5675 50  0001 L CNN
F 3 "" H 9350 5775 50  0001 L CNN
F 4 "XXXX" H 9342 5650 50  0000 L CNN "Package Size"
F 5 "Voltage" H 9342 5559 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 9342 5468 50  0000 L CNN "MPN"
F 7 "-" H 9350 5400 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 9350 5400 50  0001 L CNN "Prefix"
F 9 "-" H 9350 5400 50  0001 L CNN "Website"
F 10 "-" H 9350 5400 50  0001 L CNN "Description"
F 11 "-" H 9350 5400 50  0001 L CNN "Manufacturer"
	1    9250 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F82A316
P 9250 6000
F 0 "#PWR?" H 9250 5750 50  0001 C CNN
F 1 "GND" H 9255 5827 50  0000 C CNN
F 2 "" H 9250 6000 50  0001 C CNN
F 3 "" H 9250 6000 50  0001 C CNN
	1    9250 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F82A31C
P 8300 6000
F 0 "#PWR?" H 8300 5750 50  0001 C CNN
F 1 "GND" H 8305 5827 50  0000 C CNN
F 2 "" H 8300 6000 50  0001 C CNN
F 3 "" H 8300 6000 50  0001 C CNN
	1    8300 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 6000 8300 5850
Wire Wire Line
	7750 5650 7650 5650
Wire Wire Line
	7650 5650 7650 5450
Wire Wire Line
	7650 5450 7750 5450
Wire Wire Line
	6900 5450 6900 5650
Wire Wire Line
	6900 5450 7650 5450
Connection ~ 7650 5450
Wire Wire Line
	9250 6000 9250 5850
Wire Wire Line
	9250 5650 9250 5450
Connection ~ 9250 5450
Text Notes 11850 2650 0    50   ~ 0
LP2985\n\nVin Max: 16 V\n\n--\n\n\nA minimum value of 1 μF (over the entire operating temperature range)\n is required at the input of the LP2985. In addition, this input capacitor \nshould be located within 1 cm of the input pin and connected to a\n clean analog ground. There are no equivalent series resistance (ESR) \nrequirements for this capacitor, and the capacitance can be increased without limit.\n\nAs an advantage over other regulators, the LP2985 permits the use of low-ESR capacitors at the output,\nincluding ceramic capacitors that can have an ESR as low as 5 mΩ. Tantalum and film capacitors also can be\nused if size and cost are not issues. The output capacitor also should be located within 1 cm of the output pin\nand be returned to a clean analog ground\n\n\n----\n\nThus, to prevent possible damage to the regulator in any application where\nthe output may be pulled above the input, or the input may be shorted to ground, an external Schottky diode\nshould be connected between the output and input. With the anode on output, this Schottky limits the reverse\nvoltage across the output and input pins to ∼0.3 V, preventing the regulator’s internal diode from forward biasing
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D?
U 1 1 5F82B13B
P 5500 3150
F 0 "D?" V 5740 3072 50  0000 R CNN
F 1 "Schottky" V 5649 3072 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 5700 3350 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5700 3450 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 5700 3550 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 5550 3072 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 5700 3750 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 5700 3850 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5700 3950 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 5700 4050 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 5700 4150 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 5700 4250 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5700 4350 60  0001 L CNN "Status"
F 13 "SOD-123" V 5452 3072 50  0000 R CNN "Package"
F 14 "0.45 V" V 5361 3072 50  0000 R CNN "Vf"
	1    5500 3150
	0    -1   -1   0   
$EndComp
Text HLabel 6250 1400 0    50   UnSpc ~ 0
V_BAT
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D?
U 1 1 5F8313FF
P 4100 3150
F 0 "D?" V 4340 3072 50  0000 R CNN
F 1 "Schottky" V 4249 3072 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 4300 3350 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 4300 3450 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 4300 3550 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 4150 3072 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4300 3750 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 4300 3850 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 4300 3950 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 4300 4050 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 4300 4150 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 4300 4250 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4300 4350 60  0001 L CNN "Status"
F 13 "SOD-123" V 4052 3072 50  0000 R CNN "Package"
F 14 "0.45 V" V 3961 3072 50  0000 R CNN "Vf"
	1    4100 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 2800 4100 2950
Wire Wire Line
	5500 2800 5500 2950
Wire Wire Line
	4100 3250 4100 3450
Wire Wire Line
	4100 3450 5500 3450
Wire Wire Line
	5500 3250 5500 3450
Text Notes 650  1300 0    50   ~ 0
V_BUS comes from USB/FTDI exclusively\n\nIf V_BUS is energized, then V_BAT is energized through battery charger.\nHowever V_BAT may be accidental short to ground, low (on battery), etc.\n\nWe want to drive the voltage regulators from V_BUS over V_BAT if available.\n\nOn/Off switch controls V_BAT, so if V_BUS is powered, switch does nothing.
Wire Wire Line
	10150 1400 10450 1400
Connection ~ 10150 1400
Wire Wire Line
	9150 3650 9150 3450
Connection ~ 9150 3450
Text HLabel 3850 2800 0    50   UnSpc ~ 0
V_BAT
Text HLabel 5350 2800 0    50   UnSpc ~ 0
V_BUS
Wire Wire Line
	5350 2800 5500 2800
Wire Wire Line
	3850 2800 4100 2800
Wire Wire Line
	5500 3450 6800 3450
Connection ~ 5500 3450
Connection ~ 6800 3450
Wire Wire Line
	10150 1250 10150 1400
Wire Wire Line
	9950 800  10150 800 
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D?
U 1 1 5F8D7F80
P 5500 5200
F 0 "D?" V 5740 5122 50  0000 R CNN
F 1 "Schottky" V 5649 5122 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 5700 5400 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5700 5500 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 5700 5600 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 5550 5122 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 5700 5800 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 5700 5900 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5700 6000 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 5700 6100 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 5700 6200 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 5700 6300 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5700 6400 60  0001 L CNN "Status"
F 13 "SOD-123" V 5452 5122 50  0000 R CNN "Package"
F 14 "0.45 V" V 5361 5122 50  0000 R CNN "Vf"
	1    5500 5200
	0    -1   -1   0   
$EndComp
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D?
U 1 1 5F8D7F91
P 4100 5200
F 0 "D?" V 4340 5122 50  0000 R CNN
F 1 "Schottky" V 4249 5122 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 4300 5400 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 4300 5500 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 4300 5600 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 4150 5122 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4300 5800 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 4300 5900 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 4300 6000 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 4300 6100 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 4300 6200 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 4300 6300 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4300 6400 60  0001 L CNN "Status"
F 13 "SOD-123" V 4052 5122 50  0000 R CNN "Package"
F 14 "0.45 V" V 3961 5122 50  0000 R CNN "Vf"
	1    4100 5200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 4800 4100 5000
Wire Wire Line
	5500 4800 5500 5000
Wire Wire Line
	4100 5300 4100 5450
Wire Wire Line
	4100 5450 5500 5450
Wire Wire Line
	5500 5300 5500 5450
Text HLabel 3850 4800 0    50   UnSpc ~ 0
V_BAT
Text HLabel 5350 4800 0    50   UnSpc ~ 0
V_BUS
Wire Wire Line
	5350 4800 5500 4800
Wire Wire Line
	3850 4800 4100 4800
Wire Wire Line
	5500 5450 6900 5450
Connection ~ 5500 5450
Connection ~ 6900 5450
Wire Wire Line
	10150 800  10150 950 
Text Notes 1350 3550 0    50   ~ 0
Cases:\nCasesI would like to protect for:\n\nV_BAT open\nV_BAT shorted to ground\nV_BAT below any of 1.8V, 3.3V, 5V\nV_BAT above any of 1.8V, 3.3V up to 4.20 V\nV_BAT reversed?\n\nV_BUS 0V\nV_BUS shorted to ground
Text Notes 8150 2750 0    50   ~ 0
V_BAT will always be below V_BUS. If I connect Schottky diode\n from output to input as directed, now have V_BUS on the V_BAT line,\n which would bypass the battery controller. Not good.\n\nInstead maybe I can put a Schottky on the output\n so the internal diode cannot forward bias.
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D?
U 1 1 5F9316A7
P 9250 1400
F 0 "D?" H 9450 850 50  0000 R CNN
F 1 "Schottky" H 9450 950 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 9450 1600 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 9450 1700 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 9450 1800 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" H 9450 1050 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 9450 2000 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 9450 2100 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 9450 2200 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 9450 2300 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 9450 2400 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 9450 2500 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9450 2600 60  0001 L CNN "Status"
F 13 "SOD-123" H 9450 1150 50  0000 R CNN "Package"
F 14 "0.45 V" H 9450 1250 50  0000 R CNN "Vf"
	1    9250 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	8700 1400 9050 1400
Wire Wire Line
	9350 1400 10150 1400
$EndSCHEMATC
