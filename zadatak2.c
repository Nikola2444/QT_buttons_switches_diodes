#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    FILE *fp;
    FILE *fp_tasters;
    FILE *fp_switches;
    float percentage;
    long int period = 20000L;
    char str[4];
    int i = 0;
    size_t num_of_bytes = 6;
    int tval1, tval2, tval3, tval4;
    int s1, s2, s3, s4;
    unsigned char leds = 0;
    char *taster_state;

    char *switches_state;
    while(1) 
    {
	
	/**************************pročitaj stanje tastera***********************/
	fp_tasters = fopen ("/dev/buttons", "r");
	if(fp_tasters == NULL)
	{
	    printf("Problem pri otvaranju /dev/buttons\n");
	    return -1;
	}

	// dinamička alokacija prostora za string u koji će biti smešteno stanje tastera
	taster_state = (char*) malloc(num_of_bytes);

	//Čitanje stringa koji predstavlja stanje tastera iz fajla /dev/buttons na koji pokazuje fp_tasters
	getline(&taster_state, &num_of_bytes, fp_tasters);

	if(fclose(fp_tasters))
	{
	    printf("Problem pri zatvaranju /dev/led\n");
	    return -1;
	}

	// Pretvaranje stanja tastera iz stringa u integer
	tval1 = taster_state[2] - 48; 
	tval2 = taster_state[3] - 48; 
	tval3 = taster_state[4] - 48; 
	tval4 = taster_state[5] - 48;
	/************************************************************/

	/**************************pročitaj stanje prekidača***********************/
	fp_switches = fopen ("/dev/switches", "r");
	if(fp_switches == NULL)
	{
	    printf("Problem pri otvaranju /dev/buttons\n");
	    return -1;
	}
	// dinamička alokacija prostora za string u koji će biti smešteno stanje prekidača
	switches_state = (char*) malloc(num_of_bytes);

	//Čitanje stringa koji predstavlja stanje tastera iz fajla /dev/switches na koji pokazuje fp_switches
	getline(&switches_state, &num_of_bytes, fp_switches);

	if(fclose(fp_switches))
	{
	    printf("Problem pri zatvaranju /dev/led\n");
	    return -1;
	}

	// Pretvaranje stanja prekidača iz stringa u integer
	s1 = switches_state[2] - 48; 
	s2 = switches_state[3] - 48; 
	s3 = switches_state[4] - 48; 
	s4 = switches_state[5] - 48; 
	/************************************************************/

	/*********************Proveri da li su prekidač S1 i taster tval1 uključeni************************/
	if (s1 == 1)
	{
	    if (tval1 == 1)
	    {
		fp = fopen("/dev/leds", "w");
		if(fp == NULL)
		{
		    printf("Problem pri otvaranju /dev/led\n");
		    return -1;
		}
		//invertovanje bita osmobitne promenljive leds
		leds = ~leds;
		// konverzija integer u string
		sprintf(str, "%d", leds);

		// upis u /dev/leds fajl
		fputs(str, fp);

		if(fclose(fp))
		{
		    printf("Problem pri zatvaranju /dev/led\n");
		    return -1;
		}

		// zaustavljanje programa na 250ms
		usleep(250000);	
	    }

	    /***********************************************************************************************/
	}
    }
    return 0;
}

