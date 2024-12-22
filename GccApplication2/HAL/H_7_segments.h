/*
 * _7_segments.h
 *
 * Created: 4/11/2023 11:43:24 PM
 *  Author: husse
 */ 


#ifndef _7_SEGMENTS_H_ 
	#define _7_SEGMENTS_H_
	#include "../MCAL/M_DIO.h"
	#include "../CPU_configuration.h"
	#include <util/delay.h>
	
	
	typedef enum{
		comon_cathode,
		comon_anode,
		comon_cathode_decoder,
		comon_anode_decoder
	}_7_segment_type;
	
	typedef enum{
		up,
		down	
	}_7_decoder_position;
	
	typedef struct{
		DIO_port_name port;	
		_7_segment_type type;
		_7_decoder_position position;
		
	}_7_segment_object;
	
	void H_7_segment_init( _7_segment_object _7_segment);
	void H_7_segment_clear( _7_segment_object _7_segment);
	void H_7_segment_display( _7_segment_object _7_segment,u8 displayed_num);
#endif /* 7_SEGMENTS_H_ */