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
L MyCapacitors:C_Small_vert C501
U 1 1 5F90528B
P 7300 2300
F 0 "C501" H 7392 2432 50  0000 L CNN
F 1 "10uF" H 7392 2341 50  0000 L CNN
F 2 "" H 7300 2275 50  0001 L CNN
F 3 "" H 7400 2375 50  0001 L CNN
F 4 "XXXX" H 7392 2250 50  0000 L CNN "Package Size"
F 5 "Voltage" H 7392 2159 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 7392 2068 50  0000 L CNN "MPN"
F 7 "-" H 7400 2000 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 7400 2000 50  0001 L CNN "Prefix"
F 9 "-" H 7400 2000 50  0001 L CNN "Website"
F 10 "-" H 7400 2000 50  0001 L CNN "Description"
F 11 "-" H 7400 2000 50  0001 L CNN "Manufacturer"
	1    7300 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0504
U 1 1 5F906D29
P 7300 2600
F 0 "#PWR0504" H 7300 2350 50  0001 C CNN
F 1 "GND" H 7305 2427 50  0000 C CNN
F 2 "" H 7300 2600 50  0001 C CNN
F 3 "" H 7300 2600 50  0001 C CNN
	1    7300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2450 7300 2600
$Comp
L MyICs:3.3V_Reg U501
U 1 1 5F80149D
P 8800 2150
F 0 "U501" H 8250 2750 60  0000 L CNN
F 1 "3.3V_Reg" H 8250 2650 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 10000 2700 60  0001 L CNN
F 3 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 9000 2450 60  0001 L CNN
F 4 "296-18476-1-ND" H 10000 2900 60  0001 L CNN "Digi-Key_PN"
F 5 "LP2985-33DBVR" H 8250 2550 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 10000 3100 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 10000 3200 60  0001 L CNN "Family"
F 8 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 10000 3300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/texas-instruments/LP2985-33DBVR/296-18476-1-ND/809911" H 10000 3400 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 3.3V 150MA SOT23-5" H 10000 3500 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 10000 3600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 10000 3700 60  0001 L CNN "Status"
F 13 "150 mA" H 8250 2450 50  0000 L CNN "Imax"
	1    8800 2150
	1    0    0    -1  
$EndComp
Text HLabel 9850 2050 2    50   UnSpc ~ 0
+3.3V
Wire Wire Line
	9850 2050 9650 2050
Wire Wire Line
	9650 2050 9200 2050
NoConn ~ 9200 2250
$Comp
L MyCapacitors:C_Small_vert C503
U 1 1 5F803AE8
P 9650 2300
F 0 "C503" H 9742 2432 50  0000 L CNN
F 1 "10uF" H 9742 2341 50  0000 L CNN
F 2 "" H 9650 2275 50  0001 L CNN
F 3 "" H 9750 2375 50  0001 L CNN
F 4 "XXXX" H 9742 2250 50  0000 L CNN "Package Size"
F 5 "Voltage" H 9742 2159 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 9742 2068 50  0000 L CNN "MPN"
F 7 "-" H 9750 2000 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 9750 2000 50  0001 L CNN "Prefix"
F 9 "-" H 9750 2000 50  0001 L CNN "Website"
F 10 "-" H 9750 2000 50  0001 L CNN "Description"
F 11 "-" H 9750 2000 50  0001 L CNN "Manufacturer"
	1    9650 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0508
U 1 1 5F804804
P 9650 2600
F 0 "#PWR0508" H 9650 2350 50  0001 C CNN
F 1 "GND" H 9655 2427 50  0000 C CNN
F 2 "" H 9650 2600 50  0001 C CNN
F 3 "" H 9650 2600 50  0001 C CNN
	1    9650 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0506
U 1 1 5F80525C
P 8700 2600
F 0 "#PWR0506" H 8700 2350 50  0001 C CNN
F 1 "GND" H 8705 2427 50  0000 C CNN
F 2 "" H 8700 2600 50  0001 C CNN
F 3 "" H 8700 2600 50  0001 C CNN
	1    8700 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2600 8700 2450
Wire Wire Line
	8150 2250 8050 2250
Wire Wire Line
	8050 2250 8050 2050
Wire Wire Line
	8050 2050 8150 2050
Wire Wire Line
	7300 2050 7300 2250
Wire Wire Line
	7300 2050 8050 2050
Connection ~ 8050 2050
Wire Wire Line
	9650 2600 9650 2450
$Comp
L MyCapacitors:C_Small_vert C502
U 1 1 5F82A2E6
P 7300 4150
F 0 "C502" H 7392 4282 50  0000 L CNN
F 1 "10uF" H 7392 4191 50  0000 L CNN
F 2 "" H 7300 4125 50  0001 L CNN
F 3 "" H 7400 4225 50  0001 L CNN
F 4 "XXXX" H 7392 4100 50  0000 L CNN "Package Size"
F 5 "Voltage" H 7392 4009 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 7392 3918 50  0000 L CNN "MPN"
F 7 "-" H 7400 3850 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 7400 3850 50  0001 L CNN "Prefix"
F 9 "-" H 7400 3850 50  0001 L CNN "Website"
F 10 "-" H 7400 3850 50  0001 L CNN "Description"
F 11 "-" H 7400 3850 50  0001 L CNN "Manufacturer"
	1    7300 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0505
U 1 1 5F82A2EC
P 7300 4450
F 0 "#PWR0505" H 7300 4200 50  0001 C CNN
F 1 "GND" H 7305 4277 50  0000 C CNN
F 2 "" H 7300 4450 50  0001 C CNN
F 3 "" H 7300 4450 50  0001 C CNN
	1    7300 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 4300 7300 4450
$Comp
L MyICs:3.3V_Reg U502
U 1 1 5F82A2FD
P 8800 4000
F 0 "U502" H 8250 4600 60  0000 L CNN
F 1 "1.8V_Reg" H 8250 4500 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 10000 4550 60  0001 L CNN
F 3 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 9000 4300 60  0001 L CNN
F 4 "296-18474-1-ND" H 10000 4750 60  0001 L CNN "Digi-Key_PN"
F 5 "LP2985-18DBVR" H 8250 4400 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 10000 4950 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 10000 5050 60  0001 L CNN "Family"
F 8 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 10000 5150 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/products/detail/texas-instruments/LP2985-18DBVR/809757" H 10000 5250 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 1.8V 150MA SOT23-5" H 10000 5350 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 10000 5450 60  0001 L CNN "Manufacturer"
F 12 "Active" H 10000 5550 60  0001 L CNN "Status"
F 13 "150 mA" H 8250 4300 50  0000 L CNN "Imax"
	1    8800 4000
	1    0    0    -1  
$EndComp
Text HLabel 9850 3900 2    50   UnSpc ~ 0
+1.8V
Wire Wire Line
	9850 3900 9650 3900
Wire Wire Line
	9650 3900 9200 3900
NoConn ~ 9200 4100
$Comp
L MyCapacitors:C_Small_vert C504
U 1 1 5F82A310
P 9650 4150
F 0 "C504" H 9742 4282 50  0000 L CNN
F 1 "10uF" H 9742 4191 50  0000 L CNN
F 2 "" H 9650 4125 50  0001 L CNN
F 3 "" H 9750 4225 50  0001 L CNN
F 4 "XXXX" H 9742 4100 50  0000 L CNN "Package Size"
F 5 "Voltage" H 9742 4009 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 9742 3918 50  0000 L CNN "MPN"
F 7 "-" H 9750 3850 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 9750 3850 50  0001 L CNN "Prefix"
F 9 "-" H 9750 3850 50  0001 L CNN "Website"
F 10 "-" H 9750 3850 50  0001 L CNN "Description"
F 11 "-" H 9750 3850 50  0001 L CNN "Manufacturer"
	1    9650 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0509
U 1 1 5F82A316
P 9650 4450
F 0 "#PWR0509" H 9650 4200 50  0001 C CNN
F 1 "GND" H 9655 4277 50  0000 C CNN
F 2 "" H 9650 4450 50  0001 C CNN
F 3 "" H 9650 4450 50  0001 C CNN
	1    9650 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0507
U 1 1 5F82A31C
P 8700 4450
F 0 "#PWR0507" H 8700 4200 50  0001 C CNN
F 1 "GND" H 8705 4277 50  0000 C CNN
F 2 "" H 8700 4450 50  0001 C CNN
F 3 "" H 8700 4450 50  0001 C CNN
	1    8700 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 4450 8700 4300
Wire Wire Line
	8150 4100 8050 4100
Wire Wire Line
	8050 4100 8050 3900
Wire Wire Line
	8050 3900 8150 3900
Wire Wire Line
	7300 3900 7300 4100
Wire Wire Line
	7300 3900 8050 3900
Connection ~ 8050 3900
Wire Wire Line
	9650 4450 9650 4300
Wire Wire Line
	9650 4100 9650 3900
Connection ~ 9650 3900
Text Notes 11850 2650 0    50   ~ 0
LP2985\n\nVin Max: 16 V\n\n--\n\n\nA minimum value of 1 μF (over the entire operating temperature range)\n is required at the input of the LP2985. In addition, this input capacitor \nshould be located within 1 cm of the input pin and connected to a\n clean analog ground. There are no equivalent series resistance (ESR) \nrequirements for this capacitor, and the capacitance can be increased without limit.\n\nAs an advantage over other regulators, the LP2985 permits the use of low-ESR capacitors at the output,\nincluding ceramic capacitors that can have an ESR as low as 5 mΩ. Tantalum and film capacitors also can be\nused if size and cost are not issues. The output capacitor also should be located within 1 cm of the output pin\nand be returned to a clean analog ground\n\n\n----\n\nThus, to prevent possible damage to the regulator in any application where\nthe output may be pulled above the input, or the input may be shorted to ground, an external Schottky diode\nshould be connected between the output and input. With the anode on output, this Schottky limits the reverse\nvoltage across the output and input pins to ∼0.3 V, preventing the regulator’s internal diode from forward biasing
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D503
U 1 1 5F82B13B
P 6350 1750
F 0 "D503" V 6590 1672 50  0000 R CNN
F 1 "Schottky" V 6499 1672 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 6550 1950 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 6550 2050 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 6550 2150 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 6400 1672 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 6550 2350 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 6550 2450 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 6550 2550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 6550 2650 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 6550 2750 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 6550 2850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6550 2950 60  0001 L CNN "Status"
F 13 "SOD-123" V 6302 1672 50  0000 R CNN "Package"
F 14 "0.45 V" V 6211 1672 50  0000 R CNN "Vf"
	1    6350 1750
	0    -1   -1   0   
$EndComp
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D501
U 1 1 5F8313FF
P 4950 1750
F 0 "D501" V 5190 1672 50  0000 R CNN
F 1 "Schottky" V 5099 1672 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 5150 1950 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5150 2050 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 5150 2150 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 5000 1672 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 5150 2350 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 5150 2450 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5150 2550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 5150 2650 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 5150 2750 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 5150 2850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5150 2950 60  0001 L CNN "Status"
F 13 "SOD-123" V 4902 1672 50  0000 R CNN "Package"
F 14 "0.45 V" V 4811 1672 50  0000 R CNN "Vf"
	1    4950 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 1400 4950 1550
Wire Wire Line
	6350 1400 6350 1550
Wire Wire Line
	4950 1850 4950 2050
Wire Wire Line
	4950 2050 6350 2050
Wire Wire Line
	6350 1850 6350 2050
Text Notes 650  1300 0    50   ~ 0
V_BUS comes from USB/FTDI exclusively\n\nIf V_BUS is energized, then V_BAT is energized through battery charger.\nHowever V_BAT may be accidental short to ground, low (on battery), etc.\n\nWe want to drive the voltage regulators from V_BUS over V_BAT if available.\n\nOn/Off switch controls V_BAT, so if V_BUS is powered, switch does nothing.
Wire Wire Line
	9650 2250 9650 2050
Connection ~ 9650 2050
Text HLabel 4700 1400 0    50   UnSpc ~ 0
V_BAT
Text HLabel 6200 1400 0    50   UnSpc ~ 0
V_BUS
Wire Wire Line
	6200 1400 6350 1400
Wire Wire Line
	4700 1400 4950 1400
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D504
U 1 1 5F8D7F80
P 6400 3650
F 0 "D504" V 6640 3572 50  0000 R CNN
F 1 "Schottky" V 6549 3572 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 6600 3850 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 6600 3950 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 6600 4050 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 6450 3572 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 6600 4250 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 6600 4350 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 6600 4450 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 6600 4550 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 6600 4650 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 6600 4750 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6600 4850 60  0001 L CNN "Status"
F 13 "SOD-123" V 6352 3572 50  0000 R CNN "Package"
F 14 "0.45 V" V 6261 3572 50  0000 R CNN "Vf"
	1    6400 3650
	0    -1   -1   0   
$EndComp
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F D502
U 1 1 5F8D7F91
P 5000 3650
F 0 "D502" V 5240 3572 50  0000 R CNN
F 1 "Schottky" V 5149 3572 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 5200 3850 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5200 3950 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 5200 4050 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 5050 3572 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 5200 4250 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 5200 4350 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5200 4450 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 5200 4550 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 5200 4650 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 5200 4750 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5200 4850 60  0001 L CNN "Status"
F 13 "SOD-123" V 4952 3572 50  0000 R CNN "Package"
F 14 "0.45 V" V 4861 3572 50  0000 R CNN "Vf"
	1    5000 3650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5000 3250 5000 3450
Wire Wire Line
	6400 3250 6400 3450
Wire Wire Line
	5000 3750 5000 3900
Wire Wire Line
	5000 3900 6400 3900
Wire Wire Line
	6400 3750 6400 3900
Text HLabel 4750 3250 0    50   UnSpc ~ 0
V_BAT
Text HLabel 6250 3250 0    50   UnSpc ~ 0
V_BUS
Wire Wire Line
	6250 3250 6400 3250
Wire Wire Line
	4750 3250 5000 3250
Text Notes 550  2450 0    50   ~ 0
Cases:\nCasesI would like to protect for:\n\nV_BAT open\nV_BAT shorted to ground\nV_BAT below any of 1.8V, 3.3V, 5V\nV_BAT above any of 1.8V, 3.3V up to 4.20 V\nV_BAT reversed?\n\nV_BUS 0V\nV_BUS shorted to ground
Text Notes 600  3200 0    50   ~ 0
V_BAT will always be below V_BUS. If I connect Schottky diode\n from output to input as directed, now have V_BUS on the V_BAT line,\n which would bypass the battery controller. Not good.\n\nIn addition I can maybe I can put a Schottky on the output\n so the internal diode cannot forward bias.
Text HLabel 4800 5700 0    50   UnSpc ~ 0
V_BUS
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F #D503
U 1 1 5F909D28
P 5000 6050
F 0 "#D503" V 5240 5972 50  0000 R CNN
F 1 "Schottky" V 5149 5972 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 5200 6250 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5200 6350 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 5200 6450 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" V 5050 5972 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 5200 6650 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 5200 6750 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 5200 6850 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 5200 6950 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 5200 7050 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 5200 7150 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5200 7250 60  0001 L CNN "Status"
F 13 "SOD-123" V 4952 5972 50  0000 R CNN "Package"
F 14 "0.45 V" V 4861 5972 50  0000 R CNN "Vf"
	1    5000 6050
	0    -1   -1   0   
$EndComp
$Comp
L MyCapacitors:C_Small_vert #C501
U 1 1 5F81B87E
P 1650 6550
F 0 "#C501" H 1742 6682 50  0000 L CNN
F 1 "10uF" H 1742 6591 50  0000 L CNN
F 2 "" H 1650 6525 50  0001 L CNN
F 3 "" H 1750 6625 50  0001 L CNN
F 4 "XXXX" H 1742 6500 50  0000 L CNN "Package Size"
F 5 "Voltage" H 1742 6409 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 1742 6318 50  0000 L CNN "MPN"
F 7 "-" H 1750 6250 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 1750 6250 50  0001 L CNN "Prefix"
F 9 "-" H 1750 6250 50  0001 L CNN "Website"
F 10 "-" H 1750 6250 50  0001 L CNN "Description"
F 11 "-" H 1750 6250 50  0001 L CNN "Manufacturer"
	1    1650 6550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0501
U 1 1 5F81B884
P 1650 6850
F 0 "#PWR0501" H 1650 6600 50  0001 C CNN
F 1 "GND" H 1655 6677 50  0000 C CNN
F 2 "" H 1650 6850 50  0001 C CNN
F 3 "" H 1650 6850 50  0001 C CNN
	1    1650 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6700 1650 6850
$Comp
L MyICs:3.3V_Reg #U501
U 1 1 5F81B895
P 3150 6400
F 0 "#U501" H 2600 7000 60  0000 L CNN
F 1 "5V_Reg" H 2600 6900 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 4350 6950 60  0001 L CNN
F 3 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 3350 6700 60  0001 L CNN
F 4 "296-20717-1-ND" H 4350 7150 60  0001 L CNN "Digi-Key_PN"
F 5 "LP2985-50DBVR" H 2600 6800 60  0000 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 4350 7350 60  0001 L CNN "Category"
F 7 "PMIC - Voltage Regulators - Linear" H 4350 7450 60  0001 L CNN "Family"
F 8 "http://www.ti.com/general/docs/suppproductinfo.tsp?distId=10&gotoUrl=http%3A%2F%2Fwww.ti.com%2Flit%2Fgpn%2Flp2985" H 4350 7550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/products/detail/texas-instruments/LP2985-50DBVR/1169351" H 4350 7650 60  0001 L CNN "DK_Detail_Page"
F 10 "IC REG LINEAR 5V 150MA SOT23-5" H 4350 7750 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 4350 7850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4350 7950 60  0001 L CNN "Status"
F 13 "150 mA" H 2600 6700 50  0000 L CNN "Imax"
	1    3150 6400
	1    0    0    -1  
$EndComp
Text HLabel 5300 6300 2    50   UnSpc ~ 0
+5V
NoConn ~ 3550 6500
$Comp
L MyCapacitors:C_Small_vert #C502
U 1 1 5F81B8A8
P 5000 6550
F 0 "#C502" H 5092 6682 50  0000 L CNN
F 1 "10uF" H 5092 6591 50  0000 L CNN
F 2 "" H 5000 6525 50  0001 L CNN
F 3 "" H 5100 6625 50  0001 L CNN
F 4 "XXXX" H 5092 6500 50  0000 L CNN "Package Size"
F 5 "Voltage" H 5092 6409 50  0000 L CNN "Voltage Rating"
F 6 "MFR P/N" H 5092 6318 50  0000 L CNN "MPN"
F 7 "-" H 5100 6250 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 5100 6250 50  0001 L CNN "Prefix"
F 9 "-" H 5100 6250 50  0001 L CNN "Website"
F 10 "-" H 5100 6250 50  0001 L CNN "Description"
F 11 "-" H 5100 6250 50  0001 L CNN "Manufacturer"
	1    5000 6550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0503
U 1 1 5F81B8AF
P 5000 6850
F 0 "#PWR0503" H 5000 6600 50  0001 C CNN
F 1 "GND" H 5005 6677 50  0000 C CNN
F 2 "" H 5000 6850 50  0001 C CNN
F 3 "" H 5000 6850 50  0001 C CNN
	1    5000 6850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0502
U 1 1 5F81B8B5
P 3050 6850
F 0 "#PWR0502" H 3050 6600 50  0001 C CNN
F 1 "GND" H 3055 6677 50  0000 C CNN
F 2 "" H 3050 6850 50  0001 C CNN
F 3 "" H 3050 6850 50  0001 C CNN
	1    3050 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 6850 3050 6700
Wire Wire Line
	2500 6500 2250 6500
Wire Wire Line
	2250 6500 2250 6300
Wire Wire Line
	2250 6300 2500 6300
Wire Wire Line
	1650 6300 1650 6500
Wire Wire Line
	1100 6300 1650 6300
Wire Wire Line
	1650 6300 2250 6300
Connection ~ 1650 6300
Connection ~ 2250 6300
Wire Wire Line
	5000 6850 5000 6700
Wire Wire Line
	5000 6500 5000 6300
Text HLabel 1100 6300 0    50   UnSpc ~ 0
V_BAT
Wire Wire Line
	5000 6300 5300 6300
Connection ~ 5000 6300
Wire Wire Line
	5000 6150 5000 6300
Wire Wire Line
	4800 5700 5000 5700
Wire Wire Line
	5000 5700 5000 5850
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F #D502
U 1 1 5F9316A7
P 4100 6300
F 0 "#D502" H 4300 5750 50  0000 R CNN
F 1 "Schottky" H 4300 5850 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 4300 6500 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 4300 6600 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 4300 6700 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" H 4300 5950 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4300 6900 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 4300 7000 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 4300 7100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 4300 7200 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 4300 7300 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 4300 7400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4300 7500 60  0001 L CNN "Status"
F 13 "SOD-123" H 4300 6050 50  0000 R CNN "Package"
F 14 "0.45 V" H 4300 6150 50  0000 R CNN "Vf"
	1    4100 6300
	-1   0    0    1   
$EndComp
Wire Wire Line
	3550 6300 3700 6300
Wire Wire Line
	4200 6300 5000 6300
$Comp
L dk_Diodes-Rectifiers-Single:1N5819HW-7-F #D501
U 1 1 5F8198A2
P 2950 5650
F 0 "#D501" H 2900 6200 50  0000 R CNN
F 1 "Schottky" H 3100 6100 50  0000 R CNN
F 2 "digikey-footprints:SOD-123" H 3150 5850 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 3150 5950 60  0001 L CNN
F 4 "1N5819HW-FDICT-ND" H 3150 6050 60  0001 L CNN "Digi-Key_PN"
F 5 "1N5819HW-7-F" H 3500 6000 60  0000 R CNN "MPN"
F 6 "Discrete Semiconductor Products" H 3150 6250 60  0001 L CNN "Category"
F 7 "Diodes - Rectifiers - Single" H 3150 6350 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/ds30217.pdf" H 3150 6450 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/1N5819HW-7-F/1N5819HW-FDICT-ND/815283" H 3150 6550 60  0001 L CNN "DK_Detail_Page"
F 10 "DIODE SCHOTTKY 40V 1A SOD123" H 3150 6650 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 3150 6750 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3150 6850 60  0001 L CNN "Status"
F 13 "SOD-123" H 3150 5900 50  0000 R CNN "Package"
F 14 "0.45 V" H 3050 5800 50  0000 R CNN "Vf"
	1    2950 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 6300 3700 5650
Wire Wire Line
	3700 5650 3150 5650
Connection ~ 3700 6300
Wire Wire Line
	3700 6300 3900 6300
Wire Wire Line
	2850 5650 2250 5650
Wire Wire Line
	2250 5650 2250 6300
Text Notes 3800 6550 0    50   ~ 0
Stops V_BUs from\n getting on V_BAT
Wire Wire Line
	6400 3900 7300 3900
Connection ~ 6400 3900
Connection ~ 7300 3900
Text Notes 550  4200 0    50   ~ 0
Connected to USB and battery, and ON: \n+5V becomes V_BUS\nV_BAT can be anywhere up to 4.2 V\n\nNot connected to USB, with battery, and ON\nV_BUS is NC\nV_BAT is between like 3 and 4.2\n\nOFF means V_BAT is NC but V_BUS can still power the regulators etc.\nWouldnt this mean that the lights would get voltages on data lines but no VCC if I wire their VCC to V_BAT instead of going through the regulator? \nDoes their datasheet say if this is ok?
Wire Notes Line
	550  7300 550  5000
Wire Notes Line
	550  5000 5950 5000
Wire Notes Line
	5950 5000 5950 7300
Wire Notes Line
	550  7300 5950 7300
Text Notes 550  7750 0    50   ~ 0
This LDO is only necessary if I add a barrel jack to charge above 5 V and want to not go above 5 V for the micro etc. \nV_BUS will be the 5V from USB.\nV_BAT cannot go above 4.2 V when connected to USB, and will drop below 3.3 if only run from battery. \n\nSo at no point will this see anything other than 5 V or lipo voltages inless I add like a barrel jack, which I won't.
Wire Notes Line
	550  7300 5950 5000
Wire Notes Line
	550  5000 5950 7300
Connection ~ 6350 2050
Wire Wire Line
	6350 2050 7300 2050
Connection ~ 7300 2050
$EndSCHEMATC
