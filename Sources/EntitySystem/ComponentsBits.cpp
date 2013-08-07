#include "ComponentsBits.h"
#include <cstdarg>

ComponentsBits::ComponentsBits(int num,...)
{
	va_list arguments;                     
	va_start ( arguments, num );           
	Init(num,arguments);
	va_end ( arguments );
}
void ComponentsBits::Init(int num,va_list arguments)
{
	for ( int x = 0; x < num; x++ )
	{
		this->set(va_arg(arguments,int));
	}	
}
ComponentsBits::ComponentsBits(int num,va_list arguments)
{
	Init(num,arguments);
}

void ComponentsBits::AddComponent(int id) 
{
	this->set(id);
}