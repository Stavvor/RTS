struct Point
{
	float x, y;
	Point(float x = 0, float y = 0) :x(x), y(y) {};
};

struct AABB
{
	Point centre;
	Point halfSize;

	AABB(Point centre = Point(), Point halfSize = Point()) : centre(centre), halfSize(halfSize) {};

	bool contains(Point a)
	{
		if (a.x < centre.x + halfSize.x && a.x > centre.x - halfSize.x)
		{
			if (a.y < centre.y + halfSize.y && a.y > centre.y - halfSize.y)
			{
				return true;
			}
		}
		return false;
	}

	bool intersects(AABB other)
	{
		//this right > that left                                          this left <s that right
		if (centre.x + halfSize.x > other.centre.x - other.halfSize.x || centre.x - halfSize.x < other.centre.x + other.halfSize.x)
		{
			// This bottom > that top
			if (centre.y + halfSize.y > other.centre.y - other.halfSize.y || centre.y - halfSize.y < other.centre.y + other.halfSize.y)
			{
				return true;
			}
		}
		return false;
	}
};

template <typename T>
struct Data
{
	Point pos;
	T load;/////////////////////////////////////////////////

	Data(Point pos = Point(), T data = NULL) : pos(pos), load(data) {};
};

struct SFace {
	int v[3];
	int n[3];
	int t[3];
};