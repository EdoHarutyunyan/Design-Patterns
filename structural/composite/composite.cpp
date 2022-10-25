#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

class Graphic {
public:
    virtual inline void draw() const = 0;
    virtual inline void remove(Graphic *g) {}
    virtual inline void add(Graphic *g) {}
    virtual ~Graphic() {}
};

class Line : public Graphic {
public:
    inline void draw() const {
        std::cout << "Line draw()" << std::endl;
    }
};

class Rectangle : public Graphic {
public:
    inline void draw() const {
        std::cout << "Rectangle draw() " << std::endl;
    }
};

class Text : public Graphic {
public:
    inline void draw() const {
        std::cout << "Text draw() " << std::endl;
    }
};

// Composite
class Picture : public Graphic {
public:
    inline void draw() const {
        // for each element in g_vec, call the draw member function
        for_each(g_vec.begin(), g_vec.end(), std::mem_fun(&Graphic::draw));
    }

    inline void add(Graphic *aGraphic) {
        g_vec.push_back(aGraphic);
    }

private:
    std::vector<Graphic*> g_vec;
};

int main()
{
  Line line;
  line.draw();

  Rectangle rect;
  rect.draw();

  Text text;
  text.draw();

  std::cout << "\nComposite:\n" << std::endl;

  Picture pic;
  pic.add(&line);
  pic.add(&rect);
  pic.add(&text);
  pic.add(&rect);
  pic.draw();

  return 0;
}
