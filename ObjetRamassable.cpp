#include "ObjetRamassable.h"

ObjetRamassable::ObjetRamassable(const Position& position) : d_position(position)
{}

ObjetRamassable::~ObjetRamassable()
{}

Position ObjetRamassable::position() const
{ return d_position; }
