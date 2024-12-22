/*
 * _7_segments.c
 *
 * Created: 4/11/2023 11:43:03 PM
 *  Author: husse
 */ 
#include "H_7_segments.h"
//#include "../UTIL/data_types.h"
u8 _7_segment_arr[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};//gfedcba
//7_segment
void H_7_segment_init( _7_segment_object _7_segment){
	if (_7_segment.type==comon_cathode)
	{
		M_DIO_set_port_direction_mask(_7_segment.port,output,0b01111111);
		M_DIO_clear_port_mask(_7_segment.port,0b011111111);
	}
	else if (_7_segment.type==comon_anode)
	{
		M_DIO_set_port_direction_mask(_7_segment.port,output,0b01111111);
		M_DIO_set_port_value_mask(_7_segment.port,0b01111111);
	}
	else if (_7_segment.type==comon_cathode_decoder)
	{
		if (_7_segment.position==up)
		{
			M_DIO_set_port_direction_mask(_7_segment.port,output,0b00001111);
			M_DIO_clear_port_mask(_7_segment.port,0b00001111);
		}
		else if (_7_segment.position==down)
		{
			M_DIO_set_port_direction_mask(_7_segment.port,output,0b11110000);
			M_DIO_clear_port_mask(_7_segment.port,0b11110000);
		}
	}
	else if (_7_segment.type==comon_anode_decoder)
	{
		if (_7_segment.position==up)
		{
			M_DIO_set_port_direction_mask(_7_segment.port,output,0b00001111);
			M_DIO_set_port_value_mask(_7_segment.port,0b00001111);
		}
		else if (_7_segment.position==down)
		{
			M_DIO_set_port_direction_mask(_7_segment.port,output,0b11110000);
			M_DIO_set_port_value_mask(_7_segment.port,0b11110000);
		}
	}
}
void H_7_segment_clear( _7_segment_object _7_segment){
	if (_7_segment.type==comon_cathode)
	{
		M_DIO_clear_port_mask(_7_segment.port,0b01111111);
	}
	else if (_7_segment.type==comon_anode)
	{
		M_DIO_set_port_value_mask(_7_segment.port,0b01111111);
	}
	else if (_7_segment.type==comon_cathode_decoder)
	{
		if (_7_segment.position==up)
		{
			M_DIO_clear_port_mask(_7_segment.port,0b00001111);
		}
		else if (_7_segment.position==down)
		{
			M_DIO_clear_port_mask(_7_segment.port,0b11110000);
		}
	}
	else if (_7_segment.type==comon_anode_decoder)
	{
		if (_7_segment.position==up)
		{
			M_DIO_set_port_value_mask(_7_segment.port,0b00001111);
		}
		else if (_7_segment.position==down)
		{
			M_DIO_set_port_value_mask(_7_segment.port,0b11110000);
		}
	}
}
void H_7_segment_display( _7_segment_object _7_segment,u8 displayed_num){
	H_7_segment_clear(_7_segment);
	if (_7_segment.type==comon_cathode)
	{
		M_DIO_set_port_value_mask(_7_segment.port,_7_segment_arr[displayed_num]);
	}
	else if (_7_segment.type==comon_anode)
	{
		M_DIO_clear_port_mask(_7_segment.port,_7_segment_arr[displayed_num]);
	}
	else if (_7_segment.type==comon_cathode_decoder)
	{
		if (_7_segment.position==up)
		{
			M_DIO_set_port_value_mask(_7_segment.port,displayed_num);
		} 
		else if (_7_segment.position==down)
		{
			M_DIO_set_port_value_mask(_7_segment.port,displayed_num<<4);
		}
	}
	else if (_7_segment.type==comon_anode_decoder)
	{
		if (_7_segment.position==up)
		{
			M_DIO_set_port_value_mask(_7_segment.port,displayed_num);
		}
		else if (_7_segment.position==down)
		{
			M_DIO_set_port_value_mask(_7_segment.port,displayed_num<<4);
		}
	}
}


	
	
	
	
	