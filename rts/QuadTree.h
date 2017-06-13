template <class T>
class Quadtree
{
private:
	//4 children
	Quadtree* nw;
	Quadtree* ne;
	Quadtree* sw;
	Quadtree* se;

	AABB boundary;

	std::vector< Data<T> > objects;

	int CAPACITY;
public:
	Quadtree<T>();
	Quadtree<T>(AABB boundary);

	~Quadtree();

	bool insert(Data<T> d);
	void subdivide();
	std::vector< Data<T> > queryRange(AABB range);
};
template <class T>
Quadtree<T>::Quadtree()
{
	CAPACITY = 4;
	nw = NULL;
	ne = NULL;
	sw = NULL;
	se = NULL;
	boundary = AABB();
	objects = std::vector< Data<T> >();
}

template <class T>
Quadtree<T>::Quadtree(AABB boundary)
{
	objects = std::vector< Data<T> >();
	CAPACITY = 4;
	nw = NULL;
	ne = NULL;
	sw = NULL;
	se = NULL;
	this->boundary = boundary;
}

template <class T>
Quadtree<T>::~Quadtree()
{
	delete nw;
	delete sw;
	delete ne;
	delete se;
}

template <class T>
void Quadtree<T>::subdivide()
{
	Point qSize = Point(boundary.halfSize.x, boundary.halfSize.y);
	Point qCentre = Point(boundary.centre.x - qSize.x, boundary.centre.y - qSize.y);
	nw = new Quadtree(AABB(qCentre, qSize));

	qCentre = Point(boundary.centre.x + qSize.x, boundary.centre.y - qSize.y);
	ne = new Quadtree(AABB(qCentre, qSize));

	qCentre = Point(boundary.centre.x - qSize.x, boundary.centre.y + qSize.y);
	sw = new Quadtree(AABB(qCentre, qSize));

	qCentre = Point(boundary.centre.x + qSize.x, boundary.centre.y + qSize.y);
	se = new Quadtree(AABB(qCentre, qSize));
}

template <class T>
bool Quadtree<T>::insert(Data<T> d)
{
	if (!boundary.contains(d.pos))
	{
		return false;
	}

	if (objects.size() < CAPACITY)
	{
		objects.push_back(d);
		return true;
	}

	if (nw == NULL)
	{
		subdivide();
	}

	if (nw->insert(d))
	{
		return true;
	}
	if (ne->insert(d))
	{
		return true;
	}
	if (sw->insert(d))
	{
		return true;
	}
	if (se->insert(d))
	{
		return true;
	}

	return false;
}

template <class T>
std::vector<Data<T> > Quadtree<T>::queryRange(AABB range)
{
	std::vector< Data<T> > pInRange;

	if (!boundary.intersects(range))
	{
		return pInRange;
	}

	for (int i = 0; i < objects.size(); i++)
	{
		if (range.contains(objects.at(i).pos))
		{
			pInRange.push_back(objects.at(i));
		}
	}

	if (nw == NULL)
	{
		return pInRange;
	}

	std::vector< Data<T> > temp = nw->queryRange(range);
	pInRange.insert(pInRange.end(), temp.begin(), temp.end());

	temp = ne->queryRange(range);
	pInRange.insert(pInRange.end(), temp.begin(), temp.end());

	temp = sw->queryRange(range);
	pInRange.insert(pInRange.end(), temp.begin(), temp.end());

	temp = se->queryRange(range);
	pInRange.insert(pInRange.end(), temp.begin(), temp.end());

	return pInRange;
}

 