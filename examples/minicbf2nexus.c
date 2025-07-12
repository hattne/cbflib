/**********************************************************************
 * minicbf2nexus.c by J. Sloan of Diamond Light Source                *
 *                                                                    *
 * CBFlib Version 0.9.3 30 May 2013                                   *
 *                                                                    *
 *                          Paul Ellis and                            *
 *         Herbert J. Bernstein (yaya@bernstein-plus-sons.com)        *
 *                                                                    *
 * (C) Copyright 2013 Herbert J. Bernstein                            *
 *                                                                    *
 **********************************************************************/

/**********************************************************************
 *                                                                    *
 * YOU MAY REDISTRIBUTE THE CBFLIB PACKAGE UNDER THE TERMS OF THE GPL *
 *                                                                    *
 * ALTERNATIVELY YOU MAY REDISTRIBUTE THE CBFLIB API UNDER THE TERMS  *
 * OF THE LGPL                                                        *
 *                                                                    *
 **********************************************************************/

/*************************** GPL NOTICES ******************************
 *                                                                    *
 * This program is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU General Public License as     *
 * published by the Free Software Foundation; either version 2 of     *
 * (the License, or (at your option) any later version.               *
 *                                                                    *
 * This program is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      *
 * GNU General Public License for more details.                       *
 *                                                                    *
 * You should have received a copy of the GNU General Public License  *
 * along with this program; if not, write to the Free Software        *
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA           *
 * 02111-1307  USA                                                    *
 *                                                                    *
 **********************************************************************/

/************************* LGPL NOTICES *******************************
 *                                                                    *
 * This library is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU Lesser General Public         *
 * License as published by the Free Software Foundation; either       *
 * version 2.1 of the License, or (at your option) any later version. *
 *                                                                    *
 * This library is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 * Lesser General Public License for more details.                    *
 *                                                                    *
 * You should have received a copy of the GNU Lesser General Public   *
 * License along with this library; if not, write to the Free         *
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,    *
 * MA  02110-1301  USA                                                *
 *                                                                    *
 **********************************************************************/

/**********************************************************************
 *                                                                    *
 *                    Stanford University Notices                     *
 *  for the CBFlib software package that incorporates SLAC software   *
 *                 on which copyright is disclaimed                   *
 *                                                                    *
 * This software                                                      *
 * -------------                                                      *
 * The term "this software", as used in these Notices, refers to      *
 * those portions of the software package CBFlib that were created by *
 * employees of the Stanford Linear Accelerator Center, Stanford      *
 * University.                                                        *
 *                                                                    *
 * Stanford disclaimer of copyright                                   *
 * --------------------------------                                   *
 * Stanford University, owner of the copyright, hereby disclaims its  *
 * copyright and all other rights in this software.  Hence, anyone    *
 * may freely use it for any purpose without restriction.             *
 *                                                                    *
 * Acknowledgement of sponsorship                                     *
 * ------------------------------                                     *
 * This software was produced by the Stanford Linear Accelerator      *
 * Center, Stanford University, under Contract DE-AC03-76SFO0515 with *
 * the Department of Energy.                                          *
 *                                                                    *
 * Government disclaimer of liability                                 *
 * ----------------------------------                                 *
 * Neither the United States nor the United States Department of      *
 * Energy, nor any of their employees, makes any warranty, express or *
 * implied, or assumes any legal liability or responsibility for the  *
 * accuracy, completeness, or usefulness of any data, apparatus,      *
 * product, or process disclosed, or represents that its use would    *
 * not infringe privately owned rights.                               *
 *                                                                    *
 * Stanford disclaimer of liability                                   *
 * --------------------------------                                   *
 * Stanford University makes no representations or warranties,        *
 * express or implied, nor assumes any liability for the use of this  *
 * software.                                                          *
 *                                                                    *
 * Maintenance of notices                                             *
 * ----------------------                                             *
 * In the interest of clarity regarding the origin and status of this *
 * software, this and all the preceding Stanford University notices   *
 * are to remain affixed to any copy or derivative of this software   *
 * made or distributed by the recipient and are to be affixed to any  *
 * copy of software made or distributed by the recipient that         *
 * contains a copy or derivative of this software.                    *
 *                                                                    *
 * Based on SLAC Software Notices, Set 4                              *
 * OTT.002a, 2004 FEB 03                                              *
 **********************************************************************/



/**********************************************************************
 *                               NOTICE                               *
 * Creative endeavors depend on the lively exchange of ideas. There   *
 * are laws and customs which establish rights and responsibilities   *
 * for authors and the users of what authors create.  This notice     *
 * is not intended to prevent you from using the software and         *
 * documents in this package, but to ensure that there are no         *
 * misunderstandings about terms and conditions of such use.          *
 *                                                                    *
 * Please read the following notice carefully.  If you do not         *
 * understand any portion of this notice, please seek appropriate     *
 * professional legal advice before making use of the software and    *
 * documents included in this software package.  In addition to       *
 * whatever other steps you may be obliged to take to respect the     *
 * intellectual property rights of the various parties involved, if   *
 * you do make use of the software and documents in this package,     *
 * please give credit where credit is due by citing this package,     *
 * its authors and the URL or other source from which you obtained    *
 * it, or equivalent primary references in the literature with the    *
 * same authors.                                                      *
 *                                                                    *
 * Some of the software and documents included within this software   *
 * package are the intellectual property of various parties, and      *
 * placement in this package does not in any way imply that any       *
 * such rights have in any way been waived or diminished.             *
 *                                                                    *
 * With respect to any software or documents for which a copyright    *
 * exists, ALL RIGHTS ARE RESERVED TO THE OWNERS OF SUCH COPYRIGHT.   *
 *                                                                    *
 * Even though the authors of the various documents and software      *
 * found here have made a good faith effort to ensure that the        *
 * documents are correct and that the software performs according     *
 * to its documentation, and we would greatly appreciate hearing of   *
 * any problems you may encounter, the programs and documents any     *
 * files created by the programs are provided **AS IS** without any   *
 * warranty as to correctness, merchantability or fitness for any     *
 * particular or general use.                                         *
 *                                                                    *
 * THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF    *
 * PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES CREATED BY USE OF THE   *
 * PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS   *
 * OR DOCUMENTS OR FILE OR FILES AND NOT WITH AUTHORS OF THE          *
 * PROGRAMS OR DOCUMENTS.                                             *
 **********************************************************************/

/**********************************************************************
 *                                                                    *
 *                           The IUCr Policy                          *
 *      for the Protection and the Promotion of the STAR File and     *
 *     CIF Standards for Exchanging and Archiving Electronic Data     *
 *                                                                    *
 * Overview                                                           *
 *                                                                    *
 * The Crystallographic Information File (CIF)[1] is a standard for   *
 * information interchange promulgated by the International Union of  *
 * Crystallography (IUCr). CIF (Hall, Allen & Brown, 1991) is the     *
 * recommended method for submitting publications to Acta             *
 * Crystallographica Section C and reports of crystal structure       *
 * determinations to other sections of Acta Crystallographica         *
 * and many other journals. The syntax of a CIF is a subset of the    *
 * more general STAR File[2] format. The CIF and STAR File approaches *
 * are used increasingly in the structural sciences for data exchange *
 * and archiving, and are having a significant influence on these     *
 * activities in other fields.                                        *
 *                                                                    *
 * Statement of intent                                                *
 *                                                                    *
 * The IUCr's interest in the STAR File is as a general data          *
 * interchange standard for science, and its interest in the CIF,     *
 * a conformant derivative of the STAR File, is as a concise data     *
 * exchange and archival standard for crystallography and structural  *
 * science.                                                           *
 *                                                                    *
 * Protection of the standards                                        *
 *                                                                    *
 * To protect the STAR File and the CIF as standards for              *
 * interchanging and archiving electronic data, the IUCr, on behalf   *
 * of the scientific community,                                       *
 *                                                                    *
 * * holds the copyrights on the standards themselves,                *
 *                                                                    *
 * * owns the associated trademarks and service marks, and            *
 *                                                                    *
 * * holds a patent on the STAR File.                                 *
 *                                                                    *
 * These intellectual property rights relate solely to the            *
 * interchange formats, not to the data contained therein, nor to     *
 * the software used in the generation, access or manipulation of     *
 * the data.                                                          *
 *                                                                    *
 * Promotion of the standards                                         *
 *                                                                    *
 * The sole requirement that the IUCr, in its protective role,        *
 * imposes on software purporting to process STAR File or CIF data    *
 * is that the following conditions be met prior to sale or           *
 * distribution.                                                      *
 *                                                                    *
 * * Software claiming to read files written to either the STAR       *
 * File or the CIF standard must be able to extract the pertinent     *
 * data from a file conformant to the STAR File syntax, or the CIF    *
 * syntax, respectively.                                              *
 *                                                                    *
 * * Software claiming to write files in either the STAR File, or     *
 * the CIF, standard must produce files that are conformant to the    *
 * STAR File syntax, or the CIF syntax, respectively.                 *
 *                                                                    *
 * * Software claiming to read definitions from a specific data       *
 * dictionary approved by the IUCr must be able to extract any        *
 * pertinent definition which is conformant to the dictionary         *
 * definition language (DDL)[3] associated with that dictionary.      *
 *                                                                    *
 * The IUCr, through its Committee on CIF Standards, will assist      *
 * any developer to verify that software meets these conformance      *
 * conditions.                                                        *
 *                                                                    *
 * Glossary of terms                                                  *
 *                                                                    *
 * [1] CIF:  is a data file conformant to the file syntax defined     *
 * at http://www.iucr.org/iucr-top/cif/spec/index.html                *
 *                                                                    *
 * [2] STAR File:  is a data file conformant to the file syntax       *
 * defined at http://www.iucr.org/iucr-top/cif/spec/star/index.html   *
 *                                                                    *
 * [3] DDL:  is a language used in a data dictionary to define data   *
 * items in terms of "attributes". Dictionaries currently approved    *
 * by the IUCr, and the DDL versions used to construct these          *
 * dictionaries, are listed at                                        *
 * http://www.iucr.org/iucr-top/cif/spec/ddl/index.html               *
 *                                                                    *
 * Last modified: 30 September 2000                                   *
 *                                                                    *
 * IUCr Policy Copyright (C) 2000 International Union of              *
 * Crystallography                                                    *
 **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#ifdef CBF_USE_ULP
#include <stdint.h>
#endif

#include "cbf.h"
#include "cbf_simple.h"
#include "img.h"
#include "cbf_string.h"
#include "cbf_copy.h"
#include "cbf_hdf5.h"
#include "cbf_getopt.h"

#ifndef UINT64_MAX
#define NO_UINT64_TYPE
#endif

#define C2CBUFSIZ 8192

#ifndef HAVE_MKSTEMP
#define mkstemp _cbf_mkstemp
int
_cbf_mkstemp(char *templ);
#endif


int local_exit (int status);
int outerror(int err);

int outerror(int err)
{
    
    if ((err&CBF_FORMAT)==CBF_FORMAT)
        fprintf(stderr, " cif2cbf: The file format is invalid.\n");
    if ((err&CBF_ALLOC)==CBF_ALLOC)
        fprintf(stderr, " cif2cbf Memory allocation failed.\n");
    if ((err&CBF_ARGUMENT)==CBF_ARGUMENT)
        fprintf(stderr, " cif2cbf: Invalid function argument.\n");
    if ((err&CBF_ASCII)==CBF_ASCII)
        fprintf(stderr, " cif2cbf: The value is ASCII (not binary).\n");
    if ((err&CBF_BINARY)==CBF_BINARY)
        fprintf(stderr, " cif2cbf: The value is binary (not ASCII).\n");
    if ((err&CBF_BITCOUNT)==CBF_BITCOUNT)
        fprintf(stderr, " cif2cbf: The expected number of bits does"
                " not match the actual number written.\n");
    if ((err&CBF_ENDOFDATA)==CBF_ENDOFDATA)
        fprintf(stderr, " cif2cbf: The end of the data was reached"
                " before the end of the array.\n");
    if ((err&CBF_FILECLOSE)==CBF_FILECLOSE)
        fprintf(stderr, " cif2cbf: File close error.\n");
    if ((err&CBF_FILEOPEN)==CBF_FILEOPEN)
        fprintf(stderr, " cif2cbf: File open error.\n");
    if ((err&CBF_FILEREAD)==CBF_FILEREAD)
        fprintf(stderr, " cif2cbf: File read error.\n");
    if ((err&CBF_FILESEEK)==CBF_FILESEEK)
        fprintf(stderr, " cif2cbf: File seek error.\n");
    if ((err&CBF_FILETELL)==CBF_FILETELL)
        fprintf(stderr, " cif2cbf: File tell error.\n");
    if ((err&CBF_FILEWRITE)==CBF_FILEWRITE)
        fprintf(stderr, " cif2cbf: File write error.\n");
    if ((err&CBF_IDENTICAL)==CBF_IDENTICAL)
        fprintf(stderr, " cif2cbf: A data block with the new name already exists.\n");
    if ((err&CBF_NOTFOUND)==CBF_NOTFOUND)
        fprintf(stderr, " cif2cbf: The data block, category, column or"
                " row does not exist.\n");
    if ((err&CBF_OVERFLOW)==CBF_OVERFLOW)
        fprintf(stderr, " cif2cbf: The number read cannot fit into the "
                "destination argument.\n        The destination has been set to the nearest value.\n");
    if ((err& CBF_UNDEFINED)==CBF_UNDEFINED)
        fprintf(stderr, " cif2cbf: The requested number is not defined (e.g. 0/0).\n");
    if ((err&CBF_NOTIMPLEMENTED)==CBF_NOTIMPLEMENTED)
        fprintf(stderr, " cif2cbf: The requested functionality is not yet implemented.\n");
    if ((err&CBF_H5ERROR)==CBF_H5ERROR)
        fprintf(stderr, " cif2cbf: HDF5 API error.\n");
    return 0;
    
}

#undef cbf_failnez
#undef cbf_onfailnez

#ifndef __FILE__

#define cbf_failnez(x) {int err; err = (x); if (err) { fprintf (stderr, \
"\nCBFlib error %d \n", err); outerror(err); local_exit (-1); }}

#define cbf_onfailnez(x,c) {int err; err = (x); if (err) { fprintf (stderr, \
"\nCBFlib error %d \n", err); \
{ c; } outerror(err); local_exit (-1); }}
#else
#ifndef __func__
#define cbf_failnez(x) {int err; err = (x); if (err) { fprintf (stderr, \
"\nCBFlib error %d at %s:%d\n", err,__FILE__,__LINE__); outerror(err); local_exit (-1); }}

#define cbf_onfailnez(x,c) {int err; err = (x); if (err) { fprintf (stderr, \
"\nCBFlib error %d at %s:%d\n", err,__FILE__,__LINE__); \
{ c; } outerror(err); local_exit (-1); }}
#else
#define cbf_failnez(x) {int err; err = (x); if (err) { fprintf (stderr, \
"\nCBFlib error %d at %s:%d(%s)\n", err,__FILE__,__LINE__,__func__); outerror(err); local_exit (-1); }}

#define cbf_onfailnez(x,c) {int err; err = (x); if (err) { fprintf (stderr, \
"\nCBFlib error %d at %s:%d(%s)\n", err,__FILE__,__LINE__,__func__); \
{ c; } outerror(err); local_exit (-1); }}

#endif
#endif


int main (int argc, char *argv [])
{
	int error = CBF_SUCCESS;
    cbf_getopt_handle opts;
	size_t cifid = 0;
	unsigned long int h5_write_flags = 0L;
	const char ** const cifin = memset(malloc(argc*sizeof(char*)),0,argc*sizeof(char*));
	const char *hdf5out = NULL;
	const char *config = NULL;
	const char *group = NULL;
    cbf_config_t * const vec = cbf_config_create();
    
	/* Attempt to read the arguments */
	if (CBF_SUCCESS != (error |= cbf_make_getopt_handle(&opts))) {
		fprintf(stderr,"Could not create a 'cbf_getopt' handle.\n");
	} else if (CBF_SUCCESS != (error |= cbf_getopt_parse(opts, argc, argv, "c(compression):C(config):g(group):o(output):Z(register):"))) {
		fprintf(stderr,"Could not parse arguments.\n");
	} else {
		int errflg = 0;
        if (!cbf_rewind_getopt_option(opts)) {
			int c = 0;
			const char * optarg = NULL;
            for(; !cbf_get_getopt_data(opts,&c,NULL,NULL,&optarg); cbf_next_getopt_option(opts)) {
                switch (c) {
                    case 'c': { /* compression */
                        if (!cbf_cistrcmp("zlib",optarg?optarg:"")) {
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                            h5_write_flags |= CBF_H5COMPRESSION_ZLIB;
                        } else if (!cbf_cistrcmp("cbf",optarg?optarg:"")
                                   ||!cbf_cistrcmp("cbf_nibble_offset",optarg?optarg:"")
                                   ||!cbf_cistrcmp("cbf-nibble-offset",optarg?optarg:"")) {
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                            h5_write_flags |= CBF_H5COMPRESSION_CBF|CBF_NIBBLE_OFFSET;
                        } else if (!cbf_cistrcmp("cbf_byte_offset",optarg?optarg:"")
                                   ||!cbf_cistrcmp("cbf-byte-offset",optarg?optarg:"")) {
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                            h5_write_flags |= CBF_H5COMPRESSION_CBF|CBF_BYTE_OFFSET;
                        } else if (!cbf_cistrcmp("lz4",optarg?optarg:"")) {
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                            h5_write_flags |= CBF_H5COMPRESSION_LZ4;
                        } else if (!cbf_cistrcmp("lz4**2",optarg?optarg:"")) {
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                            h5_write_flags |= CBF_H5COMPRESSION_LZ4_2;
                        } else if (!cbf_cistrcmp("bslz4",optarg?optarg:"")) {
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                            h5_write_flags |= CBF_H5COMPRESSION_BSLZ4;
                        } else if (!cbf_cistrcmp("none",optarg?optarg:"")) {
                            /* remove any previously set (system default?) compressions */
                            h5_write_flags &= ~(CBF_COMPRESSION_MASK|CBF_FLAG_MASK);
                        }
                        else ++errflg;
                        break;
                    }
                    case 'C': { /* config file */
                        if (config) errflg++;
                        else config = optarg;
                        break;
                    }
                    case 'g': { /* group within output file where data should be stored */
                        if (group) errflg++;
                        else group = optarg;
                        break;
                    }
                    case 'o': { /* output file */
                        if (hdf5out) errflg++;
                        else hdf5out = optarg;
                        break;
                    }
                    case 'Z': { /* automatic or manual filter registration? */
                        if (cbf_cistrcmp(optarg?optarg:"","manual") == 0) {
                            h5_write_flags |= CBF_H5_REGISTER_COMPRESSIONS;
                        } else if (cbf_cistrcmp(optarg?optarg:"","plugin") == 0) {
                            h5_write_flags &= ~CBF_H5_REGISTER_COMPRESSIONS;
                        } else {
                            errflg++;
                        }
                        break;
                    }
                    case 0: { /* input file */
                        if (NULL != optarg) cifin[cifid++] = optarg;
                        break;
                    }
                    default: {
                        errflg++;
                        break;
                    }
                }
            }
        }
        if (!hdf5out) {
            fprintf(stderr,"No output file given.\n");
            ++errflg;
        }
        if (!cifid) {
            fprintf(stderr,"No input files given.\n");
            ++errflg;
        }
        if (!config) {
            fprintf(stderr,"No config file given.\n");
            ++errflg;
        }
        if (errflg) {
			fprintf(stderr, "Usage:\n\t%s [options] -C|--config config_file -o|--output output_nexus input_minicbf_files...\n"
                    "Options:\n"
                    "\t-c|--compression cbf|cbf-byte-offset|lz4|lz4**2|bslz4|zlib|none (default: none)\n"
                    "\t-g|--group output_group (default: 'entry')\n"
                    "\t-Z|--register manual|plugin (default: plugin)\n"
                    "These options are NOT case-sensitive.\n",
                    argv[0]);
			error |= CBF_ARGUMENT;
        }
	}
    
	/* parse the config file */
	if (CBF_SUCCESS == error) {
		int configError = cbf_configError_success;
		FILE * const configFile = fopen(config, "r");
		configError = cbf_config_parse(configFile, stderr, vec);
		fclose(configFile);
		if (cbf_configError_success != configError) {
			fprintf(stderr, "config parsing error: %s\n", cbf_config_strerror(configError));
			error |= CBF_UNDEFINED;
		}
	}
    
	if (CBF_SUCCESS == error) {
		size_t f = 0;
        /* prepare the output file */
		cbf_h5handle h5out = NULL;
		if(CBF_SUCCESS != (error |= cbf_create_h5handle2(&h5out,hdf5out))) {
			fprintf(stderr,"Couldn't open the HDF5 file '%s'.\n", hdf5out);
		} else if (CBF_SUCCESS != (error |= cbf_h5handle_require_entry_definition(h5out,0,group,"NXmx","1.2",0))) {
			fprintf(stderr,"Couldn't create an NXentry group in the HDF5 file '%s'.\n", hdf5out);
		} else {
            h5out->flags = h5_write_flags;
		}
        
#ifdef CBF_USE_ULP
        /* set up some parameters for comparing floating point numbers */
        h5out->cmp_double_as_float = 0;
        h5out->float_ulp = 4;
#ifndef NO_UINT64_TYPE
        h5out->double_ulp = 4;
#endif
#endif
		for (f = 0; CBF_SUCCESS == error && f != cifid; ++f) {
			cbf_handle cif = NULL;
			char ciftmp[] = "/tmp/cif2cbfXXXXXX";
    		int ciftmpfd;
			/* Get suitable file - reading from stdin to a temporary file if needed */
			if (!(cifin[f]) || strcmp(cifin[f]?cifin[f]:"","-") == 0) {
				FILE *file = NULL;
				int nbytes;
				char buf[C2CBUFSIZ];
                if ((ciftmpfd = mkstemp(ciftmp)) == -1 ) {
                    fprintf(stderr,"%s: Can't create temporary file %s.\n%s\n", argv[0], ciftmp,strerror(errno));
					error |= CBF_FILEOPEN;
				} else if ((file = fdopen(ciftmpfd, "w+")) == NULL) {
                    fprintf(stderr,"Can't open temporary file %s.\n%s\n", ciftmp,strerror(errno));
					error |= CBF_FILEOPEN;
                }
                while ((nbytes = fread(buf, 1, C2CBUFSIZ, stdin))) {
                    if(nbytes != fwrite(buf, 1, nbytes, file)) {
                        fprintf(stderr,"Failed to write %s.\n", ciftmp);
						error |= CBF_FILEWRITE;
						break;
                    }
                }
                fclose(file);
                cifin[f] = ciftmp;
            }
            
			/* Read the file */
			if (CBF_SUCCESS == error) {
				/* start timing */
				clock_t a = clock(), b;
				/* prepare the file */
				FILE * in = NULL;
				if (NULL == (in = fopen(cifin[f], "rb"))) {
                    fprintf (stderr,"Couldn't open the input CIF file '%s': %s\n", cifin[f], strerror(errno));
					error |= CBF_FILEREAD;
                }
				/* ensure temporary file is removed when the program closes */
				if (ciftmp == cifin[f]) {
                    if (unlink(ciftmp)) {
                        fprintf(stderr,"Can't unlink temporary file '%s': %s\n", ciftmp,strerror(errno));
						error |= CBF_FILECLOSE;
                    }
                }
				if (CBF_SUCCESS == error) {
					/* make the handle */
					if (CBF_SUCCESS != (error |= cbf_make_handle(&cif))) {
                        fprintf(stderr,"Failed to create handle for input_cif\n");
						error |= CBF_ALLOC;
					} else if (CBF_SUCCESS != (error |= cbf_read_file(cif, in, MSG_DIGEST))) {
						fprintf(stderr,"Couldn't read the input CIF file '%s': %s\n", cifin[f], cbf_strerror(error));
						error |= CBF_FILEREAD;
					} else {
						/* ensure the file can be cleaned up after any errors but is not accidentally closed */
						in = NULL;
                    }
                }
				/* clean up local variables */
				if (in) fclose(in);
				/* stop timing */
                b = clock ();
				printf("Time to read '%s': %.3fs\n", cifin[f], ((float)(b - a))/CLOCKS_PER_SEC);
            }
            
			/* Do the conversion */
			if (CBF_SUCCESS == error) {
				/* start timing */
				clock_t a = clock(), b;
				error |= cbf_write_minicbf_h5file(cif, h5out, vec);
				/* stop timing */
                b = clock ();
				printf("Time to convert '%s': %.3fs\n", cifin[f], ((float)(b - a))/CLOCKS_PER_SEC);
			}
            
			/* Clean up */
			if (cif) cbf_free_handle(cif);
            
            cbf_failnez(error);
        }
        
		{ /* Write the file/close the handle */
			/* start timing */
			clock_t a = clock(), b;
            /* clean up cbf handles */
			error |= cbf_free_h5handle(h5out);
			/* stop timing */
            b = clock ();
			printf("Time to write '%s': %.3fs\n", hdf5out, ((float)(b - a))/CLOCKS_PER_SEC);
        }
        
        /******************************************************************************************************/
        
	}
    
	/* Cleanup */
	free(cifin);
	cbf_config_free(vec);
	error |= cbf_free_getopt_handle(opts);
	return CBF_SUCCESS==error ? 0 : 1;
}

int local_exit (int status)
{
    exit(status);
    return 1; /* avoid warnings */
}

