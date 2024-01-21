#include "dsf.h"
#include "dsdiff.h"
#include "dsf2dsdiff.h"
#include <inttypes.h>
#include <stdio.h>

// get duration in human-readable form
void duration_hr(dsfinfo dsf)
{
	uint64_t samples = dsf.samples;
	uint64_t minutes = samples / dsf.fs / 60;
	samples -= minutes * 60 * dsf.fs;
	double seconds = (double)samples / dsf.fs;

	fprintf(stderr, "Length: %llu:%05.2f\n", minutes, seconds);
}

int main(int argc, char **argv)
{
	ASSERT(argv[1], "Error: No input file specified");
	FILE *infile;
	ASSERT(infile = fopen(argv[1], "rb"), "Error: Couldn't open input file");

	check_dsf_headers(&infile); // make sure it's a dsf file
	dsfinfo dsf = dsfinfo_load(&infile);
	check_dsf_metadata(dsf); // could help in some cases of broken files

	fprintf(stderr, "\nFile %s: ", argv[1]);
	double fsMHz = (double)dsf.fs / 1000000; // a bit simpler than printing "DSD64" etc.
	fprintf(stderr, "%lf MHz, \n", fsMHz);
	char duration[27] = {0};
	duration_hr(dsf);

	fprintf(stderr, "Writing to stdout...\n\n");
	write_DSD(&infile, dsf); // do the actual conversion

	fclose(infile);
	return 0;
}
