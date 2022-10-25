#include <iostream>
#include <string>

class Window  {
	public:
		virtual void draw() = 0;
		virtual std::string get_description() = 0;
		virtual ~Window() {}
};

class Simple_window : public Window {
	public:
		void draw() {}
        std::string get_description() {
			return "simple window\n";
		}
};

class Window_decorator : public Window  {
	protected:
		Window *m_decorated_window;

	public:
		Window_decorator (Window *decorated_window) : m_decorated_window(decorated_window) {}
};

class VerticalScrollBarDecorator : public Window_decorator {
	public:
		VerticalScrollBarDecorator (Window *decorated_window) : Window_decorator(decorated_window) {}

		void draw() {
			drawVerticalScrollBar();
			m_decorated_window->draw();
		}

        std::string get_description() {
			return m_decorated_window->get_description() + "with vertical scrollbars\n";
		}

	private:
		void drawVerticalScrollBar() {
		}
};

class HorizontalScrollBarDecorator : public Window_decorator {
	public:
		HorizontalScrollBarDecorator (Window *decorated_window) : Window_decorator(decorated_window) {}

		void draw() {
			drawHorizontalScrollBar();
			m_decorated_window->draw();
		}

        std::string get_description() {
			return m_decorated_window->get_description() + "with horizontal scrollbars\n";
		}
	private:
		void drawHorizontalScrollBar() {}
};

int main()
{
	Window *simple = new Simple_window();
    std::cout << simple -> get_description() << std::endl;

	Window *horiz = new HorizontalScrollBarDecorator (new Simple_window());
    std::cout << horiz -> get_description() << std::endl;

	Window *vert = new VerticalScrollBarDecorator (new Simple_window());
    std::cout << vert -> get_description() << std::endl;

	Window *decoratedWindow = new HorizontalScrollBarDecorator (new VerticalScrollBarDecorator(new Simple_window()));
    std::cout << decoratedWindow -> get_description() << std::endl;

	return 0;
}
