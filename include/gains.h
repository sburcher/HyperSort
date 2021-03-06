#ifndef GAINS_H
#define GAINS_H

#define GE_GAIN_DIVIDE 1.0

float ExGains[24*8][2] = {
{	0	,	1}, //Ring 0  Sector 0
{	0	,	1}, //Ring 0  Sector 1
{	0	,	1}, //Ring 0  Sector 2
{	0	,	1}, //Ring 0  Sector 3
{	0	,	1}, //Ring 0  Sector 4
{	0	,	1}, //Ring 0  Sector 5
{	0	,	1}, //Ring 0  Sector 6
{	0	,	1}, //Ring 0  Sector 7
{	0	,	1}, //Ring 1  Sector 0
{	0	,	1}, //Ring 1  Sector 1
{	0	,	1}, //Ring 1  Sector 2
{	0	,	1}, //Ring 1  Sector 3
{	0	,	1}, //Ring 1  Sector 4
{	0	,	1}, //Ring 1  Sector 5
{	0	,	1}, //Ring 1  Sector 6
{	0	,	1}, //Ring 1  Sector 7
{	-52.6441	,	0.975351}, //Ring 2  Sector 0
{	45.753	,	0.964726}, //Ring 2  Sector 1
{	-50.0075	,	0.972769}, //Ring 2  Sector 2
{	-14.6294	,	0.967259}, //Ring 2  Sector 3
{	0	,	1}, //Ring 2  Sector 4
{	-19.724	,	0.965681}, //Ring 2  Sector 5
{	-56.6014	,	0.980873}, //Ring 2  Sector 6
{	-76.1978	,	0.990277}, //Ring 2  Sector 7
{	0.0269231	,	0.975692}, //Ring 3  Sector 0
{	65.0475	,	0.964726}, //Ring 3  Sector 1
{	-56.1845	,	0.979943}, //Ring 3  Sector 2
{	4.06125	,	0.968904}, //Ring 3  Sector 3
{	0	,	1}, //Ring 3  Sector 4
{	-15.3168	,	0.968904}, //Ring 3  Sector 5
{	-26.1908	,	0.97628}, //Ring 3  Sector 6
{	-33.1175	,	0.985593}, //Ring 3  Sector 7
{	5.11202	,	0.977337}, //Ring 4  Sector 0
{	62.0953	,	0.969217}, //Ring 4  Sector 1
{	-49.2786	,	0.980946}, //Ring 4  Sector 2
{	3.94224	,	0.969217}, //Ring 4  Sector 3
{	0	,	1}, //Ring 4  Sector 4
{	4.06125	,	0.968904}, //Ring 4  Sector 5
{	-13.6301	,	0.975351}, //Ring 4  Sector 6
{	-12.6095	,	0.983577}, //Ring 4  Sector 7
{	17.7536	,	0.976324}, //Ring 5  Sector 0
{	65.0475	,	0.964726}, //Ring 5  Sector 1
{	-36.5857	,	0.979943}, //Ring 5  Sector 2
{	9.13176	,	0.970794}, //Ring 5  Sector 3
{	0	,	1}, //Ring 5  Sector 4
{	-3.62597	,	0.970166}, //Ring 5  Sector 5
{	-13.6301	,	0.975351}, //Ring 5  Sector 6
{	-13.4057	,	0.985593}, //Ring 5  Sector 7
{	2.61204	,	0.979943}, //Ring 6  Sector 0
{	54.0152	,	0.972098}, //Ring 6  Sector 1
{	-36.5857	,	0.979943}, //Ring 6  Sector 2
{	1.4763	,	0.971774}, //Ring 6  Sector 3
{	0	,	1}, //Ring 6  Sector 4
{	3.94224	,	0.969217}, //Ring 6  Sector 5
{	-14.4347	,	0.977337}, //Ring 6  Sector 6
{	-15.9936	,	0.988249}, //Ring 6  Sector 7
{	10.3424	,	0.978943}, //Ring 7  Sector 0
{	59.7827	,	0.971774}, //Ring 7  Sector 1
{	-34.7432	,	0.979302}, //Ring 7  Sector 2
{	-0.934831	,	0.97432}, //Ring 7  Sector 3
{	0	,	1}, //Ring 7  Sector 4
{	3.94224	,	0.969217}, //Ring 7  Sector 5
{	-29.6597	,	0.980946}, //Ring 7  Sector 6
{	-15.9936	,	0.988249}, //Ring 7  Sector 7
{	25.3839	,	0.975351}, //Ring 8  Sector 0
{	62.7514	,	0.967259}, //Ring 8  Sector 1
{	-28.8153	,	0.978943}, //Ring 8  Sector 2
{	4.7158	,	0.967259}, //Ring 8  Sector 3
{	0	,	1}, //Ring 8  Sector 4
{	-28.8809	,	0.977263}, //Ring 8  Sector 5
{	-14.4347	,	0.977337}, //Ring 8  Sector 6
{	-7.28768	,	0.985172}, //Ring 8  Sector 7
{	272	,	1.02818}, //Ring 9  Sector 0
{	51.6306	,	0.974685}, //Ring 9  Sector 1
{	-30.4211	,	0.982927}, //Ring 9  Sector 2
{	0.710964	,	0.973744}, //Ring 9  Sector 3
{	0	,	1}, //Ring 9  Sector 4
{	-3.62597	,	0.970166}, //Ring 9  Sector 5
{	-29.6597	,	0.980946}, //Ring 9  Sector 6
{	-8.9622	,	0.98926}, //Ring 9  Sector 7
{	1.85562	,	0.981941}, //Ring 10  Sector 0
{	62.0953	,	0.969217}, //Ring 10  Sector 1
{	-14.4347	,	0.977337}, //Ring 10  Sector 2
{	8.35868	,	0.972769}, //Ring 10  Sector 3
{	0	,	1}, //Ring 10  Sector 4
{	-6.09351	,	0.97272}, //Ring 10  Sector 5
{	-17.7832	,	0.981941}, //Ring 10  Sector 6
{	-9.67381	,	0.99127}, //Ring 10  Sector 7
{	7.06204	,	0.983577}, //Ring 11  Sector 0
{	55.2323	,	0.968212}, //Ring 11  Sector 1
{	-24.6496	,	0.980909}, //Ring 11  Sector 2
{	22.6721	,	0.971154}, //Ring 11  Sector 3
{	0	,	1}, //Ring 11  Sector 4
{	-4.31071	,	0.972098}, //Ring 11  Sector 5
{	-16.9868	,	0.979943}, //Ring 11  Sector 6
{	-19.3884	,	0.992957}, //Ring 11  Sector 7
{	24.6588	,	0.977337}, //Ring 12  Sector 0
{	62.0953	,	0.969217}, //Ring 12  Sector 1
{	-29.6597	,	0.980946}, //Ring 12  Sector 2
{	-6.09351	,	0.97272}, //Ring 12  Sector 3
{	0	,	1}, //Ring 12  Sector 4
{	-21.2993	,	0.976324}, //Ring 12  Sector 5
{	-16.9868	,	0.979943}, //Ring 12  Sector 6
{	-6.30203	,	0.986567}, //Ring 12  Sector 7
{	23.0086	,	0.977922}, //Ring 13  Sector 0
{	62.0953	,	0.969217}, //Ring 13  Sector 1
{	-38.7306	,	0.984112}, //Ring 13  Sector 2
{	0.710964	,	0.973744}, //Ring 13  Sector 3
{	0	,	1}, //Ring 13  Sector 4
{	-11.0967	,	0.972769}, //Ring 13  Sector 5
{	-25.2726	,	0.984569}, //Ring 13  Sector 6
{	6.30618	,	0.985593}, //Ring 13  Sector 7
{	24.6588	,	0.977337}, //Ring 14  Sector 0
{	39.6607	,	0.973744}, //Ring 14  Sector 1
{	-16.9868	,	0.979943}, //Ring 14  Sector 2
{	-14.4347	,	0.977337}, //Ring 14  Sector 3
{	0	,	1}, //Ring 14  Sector 4
{	-18.7639	,	0.973744}, //Ring 14  Sector 5
{	-15.1572	,	0.979302}, //Ring 14  Sector 6
{	5.63355	,	0.987586}, //Ring 14  Sector 7
{	22.2109	,	0.979943}, //Ring 15  Sector 0
{	55.2323	,	0.968212}, //Ring 15  Sector 1
{	-52.8294	,	0.985593}, //Ring 15  Sector 2
{	-14.4347	,	0.977337}, //Ring 15  Sector 3
{	0	,	1}, //Ring 15  Sector 4
{	-17.9592	,	0.971774}, //Ring 15  Sector 5
{	-40.0455	,	0.984571}, //Ring 15  Sector 6
{	11.5781	,	0.987227}, //Ring 15  Sector 7
{	22.2109	,	0.979943}, //Ring 16  Sector 0
{	39.0546	,	0.975692}, //Ring 16  Sector 1
{	-44.0793	,	0.982549}, //Ring 16  Sector 2
{	-13.6301	,	0.975351}, //Ring 16  Sector 3
{	0	,	1}, //Ring 16  Sector 4
{	-26.3442	,	0.974685}, //Ring 16  Sector 5
{	-35.7586	,	0.988249}, //Ring 16  Sector 6
{	3.77139	,	0.988249}, //Ring 16  Sector 7
{	22.2109	,	0.979943}, //Ring 17  Sector 0
{	39.6607	,	0.973744}, //Ring 17  Sector 1
{	-26.9835	,	0.978304}, //Ring 17  Sector 2
{	-13.6301	,	0.975351}, //Ring 17  Sector 3
{	0	,	1}, //Ring 17  Sector 4
{	-35.6668	,	0.977922}, //Ring 17  Sector 5
{	-46.8172	,	0.983502}, //Ring 17  Sector 6
{	284.39	,	1.03583}, //Ring 17  Sector 7
{	22.2109	,	0.979943}, //Ring 18  Sector 0
{	27.1608	,	0.974722}, //Ring 18  Sector 1
{	-39.1339	,	0.982538}, //Ring 18  Sector 2
{	0.994393	,	0.972992}, //Ring 18  Sector 3
{	0	,	1}, //Ring 18  Sector 4
{	-17.9592	,	0.971774}, //Ring 18  Sector 5
{	-32.2811	,	0.983577}, //Ring 18  Sector 6
{	3.02432	,	0.990277}, //Ring 18  Sector 7
{	9.57811	,	0.980946}, //Ring 19  Sector 0
{	25.3839	,	0.975351}, //Ring 19  Sector 1
{	-29.6597	,	0.980946}, //Ring 19  Sector 2
{	-14.4347	,	0.977337}, //Ring 19  Sector 3
{	0	,	1}, //Ring 19  Sector 4
{	-36.5857	,	0.979943}, //Ring 19  Sector 5
{	-33.1175	,	0.985593}, //Ring 19  Sector 6
{	3.77139	,	0.988249}, //Ring 19  Sector 7
{	21.4944	,	0.981941}, //Ring 20  Sector 0
{	40.3473	,	0.971774}, //Ring 20  Sector 1
{	-40.0455	,	0.984571}, //Ring 20  Sector 2
{	-23.7791	,	0.978893}, //Ring 20  Sector 3
{	0	,	1}, //Ring 20  Sector 4
{	-33.9815	,	0.977337}, //Ring 20  Sector 5
{	-33.1175	,	0.985593}, //Ring 20  Sector 6
{	11.5781	,	0.987227}, //Ring 20  Sector 7
{	5.11202	,	0.977337}, //Ring 21  Sector 0
{	17.7536	,	0.976324}, //Ring 21  Sector 1
{	-63.3011	,	0.989235}, //Ring 21  Sector 2
{	-22.0957	,	0.978306}, //Ring 21  Sector 3
{	0	,	1}, //Ring 21  Sector 4
{	-51.9526	,	0.983577}, //Ring 21  Sector 5
{	-48.5326	,	0.98926}, //Ring 21  Sector 6
{	11.1165	,	0.988445}, //Ring 21  Sector 7
{	334.997	,	1.01695}, //Ring 22  Sector 0
{	17.7536	,	0.976324}, //Ring 22  Sector 1
{	-27.6704	,	0.980251}, //Ring 22  Sector 2
{	-14.4347	,	0.977337}, //Ring 22  Sector 3
{	0	,	1}, //Ring 22  Sector 4
{	-36.5857	,	0.979943}, //Ring 22  Sector 5
{	-40.0455	,	0.984571}, //Ring 22  Sector 6
{	-46.8995	,	0.995651}, //Ring 22  Sector 7
{	0	,	1}, //Ring 23  Sector 0
{	0	,	1}, //Ring 23  Sector 1
{	0	,	1}, //Ring 23  Sector 2
{	0	,	1}, //Ring 23  Sector 3
{	0	,	1}, //Ring 23  Sector 4
{	0	,	1}, //Ring 23  Sector 5
{	0	,	1}, //Ring 23  Sector 6
{	0	,	1}, //Ring 23  Sector 7
};

/*
float LeafCalibration[48][3] = {
	{-37.7869,	1.1324,		-5.17715e-06},// 0 C1L1
	{-37.8348,	1.10738,	-9.71729e-06},// 1 C1L2
	{-33.6473,	1.1304,		-7.04405e-06},// 2 C1L3
	{-38.5324,	1.12257,	-1.39457e-05},// 3 C1L4
	{-36.1303,	1.16389,	-7.69838e-06},// 4 C2L1
	{-35.7412,	1.14564,	-1.23364e-05},// 5 C2L2
	{-36.2931,	1.13711,	-7.48408e-06},// 6 C2L3
	{-36.4952,	1.15274,	-7.6951e-06},// 7 C2L4
	{-25.4553,	1.14552,	-9.22237e-06},// 8 C3L1
	{-21.0639,	1.12244,	-1.18242e-05},// 9 C3L2
	{-20.3137,	0.940408,	-4.96202e-06},// 10 C3L3
	{-18.3159,	1.07695,	-9.48677e-06},// 11 C3L4
	{-27.5023,	1.16496,	-6.53845e-06},// 12 C4L1
	{-23.5638,	1.16271,	-6.5195e-06},// 13 C4L2
	{-25.665,	1.10423,	-5.10393e-06},// 14 C4L3
	{-22.5499,	1.17172,	-1.0707e-05},// 15 C4L4
	{-22.6092,	1.10298,	-1.25897e-05},// 16 C5L1
	{-29.5599,	1.10037,	-1.0596e-05},// 17 C5L2
	{-37.0329,	1.07479,	-4.8762e-06},// 18 C5L3
	{-35.6949,	1.03639,	-6.03212e-06},// 19 C5L4
	{-39.1363,	1.10982,	-1.13586e-05},// 20 C6L1
	{-36.9032,	1.09472,	-7.33236e-06},// 21 C6L2
	{-37.766,	1.12818,	-6.43345e-06},// 22 C6L3
	{-33.6225,	1.0856,		-7.27618e-06},// 23 C6L4
	{-43.1212,	1.11526,	-5.87684e-06},// 24 C7L1
	{0,0,0},// 25 C7L2 ***Double peak***
	{0,0,0},// 26 C7L3 ***Double peak***
	{-43.8624,	1.10867,	-8.59657e-06},// 27 C7L4
	{-43.2214,	1.10331,	-4.48934e-06},// 28 C8L1
	{-44.1273,	1.15948,	-7.62138e-06},// 29 C8L2
	{-46.4716,	1.1975,		-2.28128e-06},// 30 C8L3
	{-37.2199,	1.06442,	-7.61852e-06},// 31 C8L4
	{-42.2385,	1.12088,	-5.54825e-06},// 32 C9L1
	{-31.7248,	1.10019,	-7.35851e-06},// 33 C9L2
	{-46.8027,	1.11782,	-9.62637e-06},// 34 C9L3
	{-31.291,	1.05869,	-2.49973e-06},// 35 C9L4
	{0,0,0},// 36 C10L1 ***Bad***
	{-31.4329,	0.984344,	-1.37409e-06},// 37 C10L2
	{-38.1391,	0.884301,	-5.5271e-06},// 38 C10L3
	{0,0,0},// 39 C10L4 ***Bad***
	{-46.4881,	1.09422,	-4.14268e-06},// 40 C11L1
	{-39.407,	1.11267,	-4.02711e-06},// 41 C11L2
	{-44.7278,	1.05185,	-4.05635e-06},// 42 C11L3
	{-38.6158,	1.07987,	-1.06949e-05},// 43 C11L4
	{-48.0881,	1.14076,	-2.84613e-06},// 44 C12L1
	{-40.2203,	1.10239,	-2.25731e-06},// 45 C12L2
	{-47.443,	1.13599,	-1.14289e-05},// 46 C12L3
	{-43.2352,	1.16283,	-1.06773e-05}// 47 C12L4
};


//Old gamma calibrations from rough online calibration

float leaf_cal[12*4][2] = { 
{	-32.251697	,	1.1202061	},
{	-29.240077	,	1.0844354	},
{	-26.43008	,	1.1151236	},
{	-25.264972	,	1.0918208	},
{	-30.210654	,	1.1470804	},
{	-26.034072	,	1.1202566	},
{	-31.084027	,	1.1198671	},
{	-31.380535	,	1.1365833	},
{	-3.5	    ,	1.28022	    },
{	-8.4032873	,	1.0965684	},
{	-13.245633	,	0.92951075	},
{	-8.3163336	,	1.0564559	},
{	-17.252039	,	1.1494882	},
{	-15.754278	,	1.1483032	},
{	-17.575862	,	1.0923918	},
{	-10.527673	,	1.1493228	},
{	-14.265783	,	1.0787211	},
{	-30.050769	,	1.0793677	},
{	-31.846917	,	1.0650299	},
{	-28.627669	,	1.0234477	},
{	-31.643867	,	1.0875114	},
{	-29.971707	,	1.0804556	},
{	-30.655778	,	1.1149432	},
{	-26.430629	,	1.0710781	},
{	-36.977764	,	1.1039504	},
{	-36.97	,	1.1	},
{	-33.60911	,	1.0922382	},
{	-35.607776	,	1.0915815	},
{	-37.364543	,	1.0937016	},
{	-37.463491	,	1.1450289	},
{	-44.231073	,	1.1940752	},
{	-30.58815	,	1.0496782	},
{	-37.671209	,	1.111022	},
{	-25.596475	,	1.086352	},
{	-37.837337	,	1.0995071	},
{	-28.918363	,	1.0541057	},
{	-44.158573	,	1.0933491	},
{	-30.045819	,	0.9809431	},
{	-32.648647	,	0.87266438	},
{	-20.287456	,	1.0103356	},
{	-42.706662	,	1.0863974	},
{	-36.960784	,	1.106149	},
{	-40.182431	,	1.0434327	},
{	-27.972336	,	1.0581109	},
{	-47.454648	,	1.1367923	},
{	-39.489002	,	1.0994372	},
{	-38.420016	,	1.1159158	},
};


float dECalibration[32][3] = {
{	134.541,	1.30348,	3.9568e-06	},
{	117.429,	1.31341,	3.4515e-06	},
{	113.257,	1.31778,	2.76766e-06	},
{	114.726,	1.31227,	3.3543e-06	},
{	142.289,	1.29865,	4.02722e-06	},
{	133.878,	1.30807,	3.67239e-06	},
{	121.591,	1.31181,	3.01664e-06	},
{	164.651,	1.30013,	4.07203e-06	},
{	163.699,	1.30339,	3.65412e-06	},
{	144.746,	1.31601,	3.23319e-06	},
{	140.031,	1.31568,	2.93168e-06	},
{	145.959,	1.31106,	3.31163e-06	},
{	139.157,	1.30966,	3.2697e-06	},
{	161.592,	1.30923,	3.77785e-06	},
{	143.893,	1.31191,	3.01664e-06	},
{	173.999,	1.30583,	3.53127e-06	},
{	174.126,	1.30345,	3.65412e-06	},
{	171.515,	1.31164,	3.17003e-06	},
{	175.937,	1.30513,	4.01291e-06	},
{	182.457,	1.30595,	3.45234e-06	},
{	184.632,	1.3031,		3.80729e-06	},
{	202.401,	1.30349,	4.11094e-06	},
{	202.401,	1.30349,	4.11094e-06	},
{	225.691,	1.29547,	4.58925e-06	},
{	85.8008,	1.32581,	9.17203e-07	},	//Sector 0
{	129.391,	1.31044,	3.59783e-06	},	//Sector 1 1.31044
{	55.2917,	1.34116,	2.43038e-08	},	//Sector 2
{	101.853,	1.32816,	1.24635e-06	},	//Sector 3
{	109.531,	1.32685,	2.84765e-06	},	//Sector 4
{	114.739,	1.32408,	2.45391e-06	},	//Sector 5
{	114.608,	1.31897,	2.72812e-06	},	//Sector 6
{	140.009,	1.31604,	3.37836e-06	}	//Sector 7
};
*/
#define SI_GAIN_DIVIDE 10.0
//Old gains from rough online calibration
float de_cal[32][2] = { 
{	53.758548	,	1.3346457	},
{	47.558256	,	1.3346235	},
{	55.934175	,	1.3373431	},
{	48.694164	,	1.3327477	},
{	60.71086	,	1.3296756	},
{	59.962938	,	1.3306627	},
{	59.69829	,	1.3333424	},
{	82.444079	,	1.3271544	},
{	87.961592	,	1.3310079	},
{	80.151507	,	1.3343442	},
{	81.31856	,	1.3347418	},
{	81.060301	,	1.3299556	},
{	73.457155	,	1.3326351	},
{	87.779557	,	1.3329107	},
{	83.675229	,	1.3325745	},
{	104.15023	,	1.3278577	},
{	100.58977	,	1.3298481	},
{	109.29723	,	1.3299391	},
{	98.721691	,	1.3336875	},
{	113.61412	,	1.3266822	},
{	107.4007	,	1.3303314	},
{	120.09131	,	1.3300301	},
{	129.41233	,	1.3267951	},
{	131.17879	,	1.3265172	},
{	74.169155	,	1.3308467	},
{	79.978089	,	1.3378395	},
{	62.948867	,	1.3383443	},
{	76.479037	,	1.3382844	},
{	69.346671	,	1.3341602	},
{	79.811447	,	1.3340742	},
{	78.099876	,	1.332923	},
{	75.971716	,	1.3394757	}
};
/*
float E1Calibration[32][3]{
{0,0,0}, //Missing channel
{0,0,0}, //Bad channel
{	-33.3166,	4.27587,	3.51279e-05	},
{	-31.0437,	4.26115,	3.57521e-05	},
{	-174.845,	4.41234,	1.70326e-06	},
{	-2.12105,	4.22149,	5.16543e-05	},
{	-134.529,	4.37227,	8.75571e-06	},
{	-12.7756,	4.26,		2.92926e-05	},
{	1.15266,	4.23208,	4.74067e-05	},
{	-99.7466,	4.35495,	3.40548e-06	},
{	-35.2819,	4.26377,	3.29139e-05	},
{	-108.27,	4.32101,	2.92897e-05	},
{	-42.5942,	4.25959,	2.92926e-05	},
{	-58.9706,	4.27545,	3.51279e-05	},
{	-81.5337,	4.23472,	5.80366e-05	},
{	-89.6671,	4.31708,	2.55939e-05	},
{	-57.937,	4.20775,	4.26669e-05	},
{	-125.876,	4.35491,	3.40548e-06	},
{	-74.9594,	4.22328,	5.55318e-05	},
{	-134.704,	4.35235,	6.17223e-06	},
{	-165.319,	4.36963,	1.15501e-05	},
{	-90.1769,	4.27613,	4.17539e-05	},
{	-63.5932,	4.23454,	5.11692e-05	},
{0,0,0}, //Bad channel
{	-77.3481,	4.27638,	4.17539e-05	}, 	// Sector 0
{	-68.829,	4.23507,	5.80367e-05	}, 	// Sector 1
{	-67.4086,	4.27239,	3.80522e-05	}, 	// Sector 2
{	-46.6542,	4.23495,	5.11692e-05	}, 	// Sector 3
{0,0,0}, // Sector 4 Missing calibration
{	-34.9446,	4.236,	5.80367e-05	}, 	// Sector 5
{	-41.1052,	4.20809,	4.2667e-05	}, // Sector 6
{	-98.3012,	4.31698,	2.55939e-05	}, // Sector 7
};
*/

//Old E1 calibration from rough online calibration
float e1_cal[32][2] = { 
{	-461.83329	,	8.8899898	},
{	239.95737	,	4.1184291	},
{	-97.92304	,	4.3356806	},
{	-89.579843	,	4.3254497	},
{	-163.82773	,	4.3698204	},
{	-89.149091	,	4.3302794	},
{	-134.36727	,	4.3537966	},
{	-60.875938	,	4.3102763	},
{	-69.342076	,	4.3205111	},
{	-80.411371	,	4.3224388	},
{	-82.098157	,	4.3188872	},
{	-143.40671	,	4.3686736	},
{	-75.30616	,	4.3072264	},
{	-125.53945	,	4.3409676	},
{	-174.71577	,	4.3681944	},
{	-103.55566	,	4.3509895	},
{	-112.94646	,	4.2992511	},
{	-89.858572	,	4.3241328	},
{	-148.77607	,	4.3511931	},
{	-94.409663	,	4.3257992	},
{	-138.91589	,	4.3612192	},
{	-121.30266	,	4.3500276	},
{	-120.34222	,	4.3470563	},
{	-119.6104	,	4.3473011	},
{	-142.94168	,	4.3606508	},
{	-167.84504	,	4.3583661	},
{	-127.26176	,	4.3345688	},
{	-144.20803	,	4.3491539	},
{	-155.25769	,	4.364813	},
{	-139.92788	,	4.365603	},
{	-116.66402	,	4.2963378	},
{	-144.03375	,	4.3698791	}
};
/*
float UpCalibration[32][3]{
{194.546,	0.69502,	2.35201e-06}, //Ring 0
{-1357.57,	1.0765,		-2.61122e-05}, //Ring 1
{-707.961,	0.900359,	-1.36508e-05}, //Ring 2
{-2159.63,	1.3053,		-4.15831e-05}, //Ring 3
{524.815,	0.566398,	1.0171e-05}, //Ring 4
{-129.367,	0.750965,	-3.26122e-06}, //Ring 5
{3163.6,	-0.163971,	6.04268e-05}, //Ring 6
{133.574,	0.664434,	2.39314e-06}, //Ring 7
{-780.838,	0.929206,	-1.5334e-05}, //Ring 8
{}, //Ring 9
{}, //Ring 10
{}, //Ring 11
{}, //Ring 12
{}, //Ring 13
{}, //Ring 14
{}, //Ring 15
{}, //Ring 16
{}, //Ring 17
{}, //Ring 18
{}, //Ring 19
{}, //Ring 20
{}, //Ring 21
{}, //Ring 22
{}, //Ring 23
{-78.15,	0.980677,	-2.94962e-06}, //Sector 0
{85.2527,	0.985311,	9.97952e-07}, //Sector 1
{148.915,	0.947798,	5.40254e-06}, //Sector 2
{596.455,	0.759384,	1.7603e-05}, //Sector 3
{46.6741,	0.956021,	7.80589e-07}, //Sector 4
{0,0,0}, //Sector 5
{73.572,	0.995663,	1.31691e-06}, //Sector 6
{260.925,	0.894645,	7.47766e-06}, //Sector 7

};
*/
float e2_cal[32][2] = { 
{	117.05801	,	0.77563047	},
{	129.09369	,	0.77275097	},
{	111.94065	,	0.77750443	},
{	131.40848	,	0.77585302	},
{	127.7485	,	0.78407987	},
{	140.6722	,	0.77783873	},
{	133.72313	,	0.7826715	},
{	143.47901	,	0.76877272	},
{	135.79458	,	0.77642016	},
{	135.34084	,	0.7688245	},
{	146.42395	,	0.76984687	},
{	152.38389	,	0.7634652	},
{	155.60647	,	0.76526174	},
{	163.43141	,	0.77668773	},
{	157.49507	,	0.7783706	},
{	166.08254	,	0.77621986	},
{	156.46341	,	0.75844563	},
{	168.63481	,	0.77139596	},
{	161.04985	,	0.77772288	},
{	151.98538	,	0.77209531	},
{	175.98887	,	0.77048471	},
{	120.62684	,	0.82524661	},
{	176.60642	,	0.7686721	},
{	120.62684	,	0.82524661	},
{	120.15026	,	0.98096094	},
{	133.45812	,	1.0547745	},
{	113.90308	,	1.0610932	},
{	141.28311	,	1.0155582	},
{	147.65484	,	1.0070459	},
{	147.65484	,	1.0070459	},
{	147.65484	,	1.0070459	},
{	147.65484	,	1.0070459	}
};

/*
//Computes the energy loss through the delta-shield and Al dead layer on dE as a function of remaining energy
//These assume the target is at 32mm for the ring angles
//All values in MeV
//f(x) = [0] + [1]*x^-1 + [2]*x^-2
float FrontDeuteron[24][3] = {
{	0.0038813,	0.26175,	-0.247976	},
{	0.00397967,	0.262755,	-0.244111	},
{	0.00409069,	0.26384,	-0.240209	},
{	0.00428329,	0.265105,	-0.239805	},
{	0.00439953,	0.266355,	-0.235216	},
{	0.00452912,	0.267681,	-0.230675	},
{	0.00475234,	0.269423,	-0.231498	},
{	0.00422203,	0.284471,	-0.26999	},
{	0.00436506,	0.28593,	-0.264391	},
{	0.00459361,	0.287544,	-0.262434	},
{	0.00474496,	0.289146,	-0.256497	},
{	0.00498554,	0.29111,	-0.255497	},
{	0.00453792,	0.305493,	-0.290422	},
{	0.004706,	0.307206,	-0.283865	},
{	0.00497258,	0.309081,	-0.281646	},
{	0.00514648,	0.310921,	-0.274848	},
{	0.0054212,	0.313162,	-0.273805	},
{	0.00490175,	0.329657,	-0.313986	},
{	0.00508984,	0.331572,	-0.306676	},
{	0.00538718,	0.333655,	-0.304262	},
{	0.0055788,	0.335681,	-0.296801	},
{	0.00522096,	0.350814,	-0.334682	},
{	0.00542214,	0.35286,	-0.32689	},
{	0.0057392,	0.355073,	-0.324372	}
};

//Computes the energy loss through the Au dead layers on dE and E1 as a function of remaining energy
//These assume the target is at 32mm for the ring angles
//All values in MeV
//f(x) = [0] + [1]*x^-1 + [2]*exp([3]*x)
float MidDeuteron[24][4] = {
{	0.0151589,	0.0390853,	0.0548982,	-0.103318	},
{	0.0152463,	0.0395203,	0.0551971,	-0.102718	},
{	0.0153568,	0.0390072,	0.0557959,	-0.10165	},
{	0.0162206,	0.0351515,	0.0597678,	-0.108917	},
{	0.0170809,	0.0299602,	0.0637038,	-0.114813	},
{	0.018664,	0.0191749,	0.0718338,	-0.127745	},
{	0.016421,	0.040602,	0.0598937,	-0.105516	},
{	0.0165628,	0.0412592,	0.0603312,	-0.10459	},
{	0.016746,	0.0409109,	0.060851,	-0.103174	},
{	0.0179471,	0.0344547,	0.0665329,	-0.111885	},
{	0.0195172,	0.0236303,	0.0745674,	-0.123732	},
{	0.0177946,	0.0427353,	0.0645756,	-0.106363	},
{	0.0179483,	0.043499,	0.0650749,	-0.105416	},
{	0.0179879,	0.041792,	0.0668183,	-0.104281	},
{	0.0198017,	0.0332476,	0.0738147,	-0.11549	},
{	0.0222873,	0.0144414,	0.0881598,	-0.134712	},
{	0.0191992,	0.0455294,	0.0697965,	-0.106671	},
{	0.0194154,	0.0456287,	0.0704359,	-0.105218	},
{	0.0205618,	0.038289,	0.0761854,	-0.111694	},
{	0.0229922,	0.0209491,	0.0893326,	-0.128356	},
{	0.0203842,	0.0484272,	0.0742752,	-0.106404	},
{	0.0206157,	0.0486672,	0.0749494,	-0.105023	},
{	0.0216954,	0.0414824,	0.0802394,	-0.110189	},
{	0.0244738,	0.0216905,	0.095212,	-0.128286	}
};

*/
#endif

