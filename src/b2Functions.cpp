#include "../Headers/b2Functions.h"

void b2SetPol(b2World &world, int x, int y, int w, int h)
{
	b2PolygonShape shape;
	shape.SetAsBox(PtoM(w), PtoM(h));
	b2BodyDef bodyDef;
	bodyDef.position.Set(PtoM(x), PtoM(y));
	world.CreateBody(&bodyDef)->CreateFixture(&shape, 1);
}