EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4400 3550 0    50   UnSpc ~ 10
V_BUS
Text HLabel 4400 3150 0    50   UnSpc ~ 10
V_BAT
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5F862DD2
P 4800 3250
AR Path="/5F780F7E/5F862DD2" Ref="Q?"  Part="1" 
AR Path="/5F85F8A8/5F862DD2" Ref="Q501"  Part="1" 
F 0 "Q501" V 5250 3300 50  0000 L CNN
F 1 "P-Channel 1.25-W MOSFET" V 5150 2350 50  0000 L CNN
F 2 "" H 5000 3350 50  0001 C CNN
F 3 "https://www.vishay.com/docs/68741/si2301cd.pdf" H 4800 3250 50  0001 C CNN
F 4 "Si2301CDS" V 5050 3050 50  0000 L CNN "MPN"
	1    4800 3250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F862DD8
P 4800 4050
AR Path="/5F780D75/5F862DD8" Ref="#PWR?"  Part="1" 
AR Path="/5F780F7E/5F862DD8" Ref="#PWR?"  Part="1" 
AR Path="/5F85F8A8/5F862DD8" Ref="#PWR0503"  Part="1" 
F 0 "#PWR0503" H 4800 3800 50  0001 C CNN
F 1 "GND" H 4805 3877 50  0000 C CNN
F 2 "" H 4800 4050 50  0001 C CNN
F 3 "" H 4800 4050 50  0001 C CNN
	1    4800 4050
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R?
U 1 1 5F862DE5
P 4800 3800
AR Path="/5F780F7E/5F862DE5" Ref="R?"  Part="1" 
AR Path="/5F85F8A8/5F862DE5" Ref="R501"  Part="1" 
F 0 "R501" H 4881 3821 50  0000 L CNN
F 1 "100K" H 4881 3730 50  0000 L CNN
F 2 "" V 4855 3750 50  0001 C CNN
F 3 "" H 4800 3800 50  0001 C CNN
F 4 "XXXX" H 4881 3730 50  0001 L CNN "Package Size"
F 5 "MFR P/N" H 5055 3639 50  0001 C CNN "MPN"
F 6 "-" H 5100 4100 50  0001 C CNN "Digi-Key_PN"
F 7 "R" H 5100 4100 50  0001 C CNN "Prefix"
F 8 "-" H 5100 4100 50  0001 C CNN "Website"
F 9 "-" H 5100 4100 50  0001 C CNN "Description"
F 10 "-" H 5100 4100 50  0001 C CNN "Manufacturer"
	1    4800 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3150 4600 3150
Wire Wire Line
	4800 4000 4800 4050
$Comp
L Diode:BAT60A D?
U 1 1 5F862DED
P 5300 3350
AR Path="/5F780F7E/5F862DED" Ref="D?"  Part="1" 
AR Path="/5F85F8A8/5F862DED" Ref="D501"  Part="1" 
F 0 "D501" V 5254 3567 50  0000 C CNN
F 1 "BAT60A" V 5345 3567 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323" H 5300 3175 50  0001 C CNN
F 3 "https://www.infineon.com/dgdl/Infineon-BAT60ASERIES-DS-v01_01-en.pdf?fileId=db3a304313d846880113def70c9304a9" H 5300 3350 50  0001 C CNN
	1    5300 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 3450 4800 3550
Wire Wire Line
	4800 3550 4400 3550
Connection ~ 4800 3550
Wire Wire Line
	4800 3550 4800 3650
Wire Wire Line
	4800 3550 5300 3550
Wire Wire Line
	5300 3550 5300 3500
Wire Wire Line
	5300 3200 5300 3150
Wire Wire Line
	5300 3150 5000 3150
Text HLabel 6650 3150 2    50   UnSpc ~ 10
V_OUT
Wire Wire Line
	5300 3150 5750 3150
Connection ~ 5300 3150
$Comp
L MyCapacitors:CP1_Small_vert C?
U 1 1 5F862E06
P 5750 3800
AR Path="/5F780D75/5F862E06" Ref="C?"  Part="1" 
AR Path="/5F780F7E/5F862E06" Ref="C?"  Part="1" 
AR Path="/5F85F8A8/5F862E06" Ref="C501"  Part="1" 
F 0 "C501" H 5841 3982 50  0000 L CNN
F 1 "10uF" H 5841 3891 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5750 3800 50  0001 C CNN
F 3 "https://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM21BR61C106KE15-01.pdf" H 5760 3870 50  0001 C CNN
F 4 "16V" H 5841 3800 50  0000 L CNN "Voltage Rating"
F 5 "0805" H 5841 3709 50  0000 L CNN "Package Size"
F 6 "GRM21BR61C106KE15L" H 5841 3618 50  0000 L CNN "MPN"
F 7 "490-3886-1-ND" H 5841 3709 50  0001 L CNN "Digi-Key_PN"
F 8 "C" H 5841 3618 50  0001 L CNN "Prefix"
F 9 "https://www.digikey.com/en/products/detail/murata-electronics/GRM21BR61C106KE15L/965928" H 5841 3527 50  0001 L CNN "Website"
F 10 "CAP CER 10UF 16V X5R 0805" H 5841 3436 50  0001 L CNN "Description"
F 11 "Murata Electronics" H 5841 3345 50  0001 L CNN "Manufacturer"
	1    5750 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3150 5750 3700
$Comp
L power:GND #PWR?
U 1 1 5F862E0D
P 5750 4050
AR Path="/5F780D75/5F862E0D" Ref="#PWR?"  Part="1" 
AR Path="/5F780F7E/5F862E0D" Ref="#PWR?"  Part="1" 
AR Path="/5F85F8A8/5F862E0D" Ref="#PWR0504"  Part="1" 
F 0 "#PWR0504" H 5750 3800 50  0001 C CNN
F 1 "GND" H 5755 3877 50  0000 C CNN
F 2 "" H 5750 4050 50  0001 C CNN
F 3 "" H 5750 4050 50  0001 C CNN
	1    5750 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4050 5750 3900
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:S2B-PH-K-S_LF__SN_ J?
U 1 1 5F862E1D
P 6100 3050
AR Path="/5F780D75/5F862E1D" Ref="J?"  Part="1" 
AR Path="/5F780F7E/5F862E1D" Ref="J?"  Part="1" 
AR Path="/5F85F8A8/5F862E1D" Ref="J501"  Part="1" 
F 0 "J501" H 6250 2800 50  0000 R CNN
F 1 "Wire Switch Here" H 6250 2900 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x2_P2mm_Drill1mm_RA" H 6300 3250 60  0001 L CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 6300 3350 60  0001 L CNN
F 4 "455-1719-ND" H 6300 3450 60  0001 L CNN "Digi-Key_PN"
F 5 "S2B-PH-K-S(LF)(SN)" H 6300 3550 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 6300 3650 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 6300 3750 60  0001 L CNN "Family"
F 8 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 6300 3850 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/jst-sales-america-inc/S2B-PH-K-S(LF)(SN)/455-1719-ND/926626" H 6300 3950 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER R/A 2POS 2MM" H 6300 4050 60  0001 L CNN "Description"
F 11 "JST Sales America Inc." H 6300 4150 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6300 4250 60  0001 L CNN "Status"
	1    6100 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 3150 6000 3150
Connection ~ 5750 3150
Wire Wire Line
	6100 3150 6500 3150
Text Notes 4100 3300 0    50   ~ 0
4.20 V max
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5F862E27
P 6500 3150
AR Path="/5F780D75/5F862E27" Ref="#FLG?"  Part="1" 
AR Path="/5F780F7E/5F862E27" Ref="#FLG?"  Part="1" 
AR Path="/5F85F8A8/5F862E27" Ref="#FLG0501"  Part="1" 
F 0 "#FLG0501" H 6500 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 6500 3323 50  0000 C CNN
F 2 "" H 6500 3150 50  0001 C CNN
F 3 "~" H 6500 3150 50  0001 C CNN
	1    6500 3150
	-1   0    0    1   
$EndComp
Connection ~ 6500 3150
Wire Wire Line
	6500 3150 6650 3150
$Comp
L pspice:VSOURCE V501
U 1 1 5F8634A6
P 2750 2800
F 0 "V501" H 3151 2846 50  0000 C CNN
F 1 "VSOURCE" H 3151 2755 50  0000 C CNN
F 2 "" H 2750 2800 50  0001 C CNN
F 3 "~" H 2750 2800 50  0001 C CNN
	1    2750 2800
	1    0    0    -1  
$EndComp
$Comp
L pspice:VSOURCE V502
U 1 1 5F864B12
P 2750 3850
F 0 "V502" H 3151 3896 50  0000 C CNN
F 1 "VSOURCE" H 3151 3805 50  0000 C CNN
F 2 "" H 2750 3850 50  0001 C CNN
F 3 "~" H 2750 3850 50  0001 C CNN
	1    2750 3850
	1    0    0    -1  
$EndComp
Text HLabel 2750 2450 0    50   UnSpc ~ 10
V_BAT
$Comp
L power:GND #PWR?
U 1 1 5F8655C3
P 2750 4200
AR Path="/5F780D75/5F8655C3" Ref="#PWR?"  Part="1" 
AR Path="/5F780F7E/5F8655C3" Ref="#PWR?"  Part="1" 
AR Path="/5F85F8A8/5F8655C3" Ref="#PWR0502"  Part="1" 
F 0 "#PWR0502" H 2750 3950 50  0001 C CNN
F 1 "GND" H 2755 4027 50  0000 C CNN
F 2 "" H 2750 4200 50  0001 C CNN
F 3 "" H 2750 4200 50  0001 C CNN
	1    2750 4200
	1    0    0    -1  
$EndComp
Text HLabel 2750 3450 0    50   UnSpc ~ 10
V_BUS
$Comp
L power:GND #PWR?
U 1 1 5F8665B6
P 2750 3150
AR Path="/5F780D75/5F8665B6" Ref="#PWR?"  Part="1" 
AR Path="/5F780F7E/5F8665B6" Ref="#PWR?"  Part="1" 
AR Path="/5F85F8A8/5F8665B6" Ref="#PWR0501"  Part="1" 
F 0 "#PWR0501" H 2750 2900 50  0001 C CNN
F 1 "GND" H 2755 2977 50  0000 C CNN
F 2 "" H 2750 3150 50  0001 C CNN
F 3 "" H 2750 3150 50  0001 C CNN
	1    2750 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4200 2750 4150
Wire Wire Line
	2750 3550 2750 3450
Wire Wire Line
	2750 3150 2750 3100
Wire Wire Line
	2750 2500 2750 2450
Wire Wire Line
	2750 2450 4400 2450
Wire Wire Line
	4400 2450 4400 3150
Wire Wire Line
	4400 3450 2750 3450
Wire Wire Line
	4400 3450 4400 3550
$EndSCHEMATC
