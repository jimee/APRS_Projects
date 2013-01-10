/* Project Swift - High altitude balloon flight software                 */
/*=======================================================================*/
/* Copyright 2010-2012 Nigel Smart <nigel@projectswift.co.uk>            */
/* And Philip Heron <phil@sanslogic.co.uk>                               */
/* Additional Help from Jon Sowman & Adam Greig of Cambridge University  */
/* Spaceflight (www.cusf.co.uk)                                          */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program. If not, see <http://www.gnu.org/licenses/>.  */

#include <stdint.h>
#include <avr/pgmspace.h>

/* 
  UK Geofence
*/
static const int32_t PROGMEM UKgeofence[50 * 2] =
{
	489924043, -36103603,
	488138903, -22610257,
	491901282, -13252978,
	496351217, -10050508,
	501037998,  11279993,
	507722758,  16260619,
	513189809,  25152367,
	520765597,  35119373,
	530454023,  42970152,
	539001634,  49909694,
	546830552,  44727668,
	551230292,  34601012,
	554336032,  29904906,
	558418741,  26487290,
	566806014,  24488896,
	575931754,  16723936,
	584164868,  11759240,
	589641150,   4293681,
	601679345,  -5502415,
	602106803, -22911888,
	598068675, -31797350,
	594741753, -52432139,
	590767750,-112927263,
	586042329,-125682437,
	573560679,-123463450,
	568484965,-110679665,
	567960819, -94029714,
	565955176, -84036460,
	562488969, -74621136,
	558888574, -68508447,
	554623831, -62193300,
	554506766, -75560492,
	552283624, -86434228,
	546950633, -86430795,
	539200807, -75704420,
	538233232, -70009827,
	537741074, -59159398,
	534700525, -58290520,
	532493620, -58085376,
	529591630, -58389442,
	522959865, -58365745,
	511047160, -84269381,
	503317712, -84353354,
	496274569, -84025146,
	486210038, -81558942,
	488754195, -70486501,
	490428397, -60384346,
	492957603, -52417139,
	493083262, -41420783,
	489924043, -36103603,
};

/* 
  Netherlands Geofence
*/
static const int32_t PROGMEM Netherlands_geofence[50 * 2] =
{
          514488390,39883889,
          514110330,38838556,
          514312617,37184444,
          514542777,37122112,
          514643665,36894322,
          514483444,35780333,
          515293836,34723780,
          516077394,36482757,
          516817886,36952827,
          517756386,38364000,
          518422071,40324890,
          518969445,40395335,
          519408830,40106111,
          519876861,40786662,
          520710555,42212225,
          521891166,43721778,
          523483441,45069109,
          524649247,45783443,
          525851776,46115887,
          527717945,46621443,
          529201665,47236889,
          529384667,48020219,
          529161114,49586889,
          530608053,52872889,
          532225889,54762888,
          533856399,59572444,
          534116553,63230666,
          534518333,67016777,
          534451943,68478332,
          533854889,68865554,
          533272777,69484445,
          532877948,70753445,
          531892999,72302328,
          527542436,70080432,
          525196410,68116550,
          522811175,70183681,
          520308732,67889388,
          518855292,65568058,
          518655267,62906899,
          518342004,60507588,
          516365691,60918946,
          512753587,61539787,
          510957625,60408220,
          509852964,59662945,
          508242311,60183763,
          508447230,57199832,
          511105610,57997496,
          513350384,52592841,
          514430127,47123166,
          513984845,42311106,
};

/* 
  Belgium Geofence
*/
static const int32_t PROGMEM Belgium_geofence[60 * 2] =
{
        507418205,29297549,
        508621627,26430958,
        511766206,27767653,
        512647495,29961666,
        513018428,30820926,
        513281201,31622408,
        513559539,31770185,
        513543426,31850186,
        513470093,31846853,
        513438239,31953516,
        513337874,31948691,
        513389724,32085382,
        513438407,32200943,
        513528611,32132407,
        513583050,32170556,
        513448987,32453888,
        513556876,33414686,
        512725590,34115858,
        512940794,35711364,
        512540246,37734641,
        512704168,40611745,
        513774752,43464127,
        514579035,45172538,
        514452544,46869905,
        514443926,48018342,
        514298852,49738425,
        513786254,51346730,
        512717126,53675100,
        512120806,56563762,
        511542698,58247255,
        510937856,58161240,
        510145384,57612748,
        509205694,57231670,
        508131079,56791790,
        507680226,57709516,
        507379776,60254454,
        506475110,61718784,
        505914620,62308409,
        505098854,62396048,
        504173681,63582258,
        503295796,63791890,
        502943527,62888536,
        501846383,61658722,
        501621237,60513233,
        500369414,58565332,
        499395150,57792494,
        498646274,57658892,
        497795007,57940247,
        496646913,58911180,
        495766640,58537182,
        495310506,55805866,
        496655702,52711844,
        498037966,49432804,
        500210204,48322457,
        500870037,47611686,
        499706534,43390428,
        501487902,41823436,
        503104468,40460152,
        504090128,36269632,
        505959650,33109167,
};

/* 
  France Geofence
*/
static const int32_t PROGMEM France_geofence[60 * 2] =
{
          427266326,7582186,
          429950404,-9315619,
          437646021,-15023628,
          450314767,-11129415,
          453225799,-7890786,
          457458936,-11214555,
          461598685,-11420592,
          464681128,-16420518,
          470775928,-21251499,
          472792972,-23395620,
          473665601,-24841991,
          475112527,-26248536,
          475601120,-27952055,
          476148323,-28378556,
          475860833,-29965953,
          475723628,-31456990,
          477142888,-31643972,
          477075546,-33240989,
          477704213,-35894842,
          478493453,-39538517,
          478685517,-43252769,
          480825341,-44939841,
          482472369,-45279657,
          482870528,-43028213,
          483618454,-43831963,
          484287295,-47507454,
          485908190,-45899611,
          486596591,-43114352,
          486813387,-39460667,
          486993463,-36992573,
          488118306,-34919481,
          488477625,-31780648,
          486758490,-28763314,
          486225724,-24082786,
          485990368,-20871129,
          486454770,-19010564,
          487507859,-15195491,
          494187713,-17724749,
          496532990,-14866333,
          493346056,-5110789,
          495510953,1716018,
          500147248,11631597,
          504685186,15850129,
          509757918,20581060,
          498241831,51756261,
          487915814,76683869,
          471081742,68457558,
          451663824,69626562,
          436134314,71664980,
          433782278,67587185,
          431658758,65172249,
          430848721,60847194,
          431127120,57938092,
          432535018,54096046,
          433762615,50083916,
          434272750,45083897,
          433056916,34851768,
          430864388,30281944,
          429070683,30259407,
          424722130,28771255,

};
