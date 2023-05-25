/*-------------------------------------------------------------------------
 *
 * kwlist_d.h
 *    List of keywords represented as a ScanKeywordList.
 *
 * Portions Copyright (c) 1996-2022, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * NOTES
 *  ******************************
 *  *** DO NOT EDIT THIS FILE! ***
 *  ******************************
 *
 *  It has been GENERATED by src/tools/gen_keywordlist.pl
 *
 *-------------------------------------------------------------------------
 */

#ifndef KWLIST_D_H
#define KWLIST_D_H

static const char ScanKeywords_kw_string[] =
	"and\0"
	"bufferedreader\0"
	"class\0"
	"classloader\0"
	"collections\0"
	"compiler\0"
	"datainputstream\0"
	"default_member_access\0"
	"entitymanager\0"
	"file\0"
	"filedescriptor\0"
	"fileinputstream\0"
	"fileoutputstream\0"
	"filepermission\0"
	"filereader\0"
	"filewriter\0"
	"inheritablethreadlocal\0"
	"io\0"
	"java\0"
	"javax\0"
	"lang\0"
	"memberaccess\0"
	"misc\0"
	"new\0"
	"not\0"
	"object\0"
	"ognl\0"
	"ognlcontext\0"
	"or\0"
	"package\0"
	"persistence\0"
	"process\0"
	"processbuilder\0"
	"runtime\0"
	"runtimepermission\0"
	"scanner\0"
	"script\0"
	"scriptenginemanage\0"
	"securitymanager\0"
	"servlet\0"
	"servletcontext\0"
	"shutdown\0"
	"sun\0"
	"system\0"
	"thread\0"
	"threadgroup\0"
	"threadlocal\0"
	"unsafe\0"
	"util\0"
	"xor";

static const uint16 ScanKeywords_kw_offsets[] = {
	0,
	4,
	19,
	25,
	37,
	49,
	58,
	74,
	96,
	110,
	115,
	130,
	146,
	163,
	178,
	189,
	200,
	223,
	226,
	231,
	237,
	242,
	255,
	260,
	264,
	268,
	275,
	280,
	292,
	295,
	303,
	315,
	323,
	338,
	346,
	364,
	372,
	379,
	398,
	414,
	422,
	437,
	446,
	450,
	457,
	464,
	476,
	488,
	495,
	500,
};

#define SCANKEYWORDS_NUM_KEYWORDS 50

static int
ScanKeywords_hash_func(const void *key, size_t keylen)
{
	static const int8 h[101] = {
		8,     39,    127,   127,   8,     127,   0,     -15,
		-19,   0,     127,   5,     -1,    127,   -2,    35,
		23,    127,   49,    127,   127,   127,   -16,   -13,
		29,    33,    3,     38,    17,    30,    127,   -26,
		-28,   0,     0,     15,    7,     0,     127,   46,
		127,   0,     127,   127,   127,   127,   127,   37,
		127,   31,    127,   0,     127,   127,   -23,   127,
		-21,   0,     56,    -11,   20,    127,   127,   22,
		0,     26,    1,     127,   21,    45,    31,    0,
		-19,   127,   23,    0,     127,   39,    0,     127,
		0,     -2,    -28,   127,   36,    37,    127,   29,
		127,   127,   -29,   0,     27,    40,    0,     48,
		127,   0,     127,   127,   0
	};

	const unsigned char *k = (const unsigned char *) key;
	uint32		a = 0;
	uint32		b = 0;

	while (keylen--)
	{
		unsigned char c = *k++ | 0x20;

		a = a * 257 + c;
		b = b * 17 + c;
	}
	return h[a % 101] + h[b % 101];
}

static const ScanKeywordList ScanKeywords = {
	ScanKeywords_kw_string,
	ScanKeywords_kw_offsets,
	ScanKeywords_hash_func,
	SCANKEYWORDS_NUM_KEYWORDS,
	22
};

#endif							/* KWLIST_D_H */