#pragma once

class ImGuiIO;

namespace sf {
	class RenderWindow;
	class Event;
	class Time;
}

class Dockspace {
public:
	/// <summary>
	/// Creates a new ImGui Dockspace using SFML as the backend.
	/// </summary>
	/// <param name="_window">(sf::RenderWindow&) : Window to render the Dockspace to.</param>
	Dockspace(sf::RenderWindow& _window);

	/// <summary>
	/// Uses SFML events to process ImGui events.
	/// </summary>
	/// <param name="_event">(const sf::Event&) : SFML event to process.</param>
	void event(const sf::Event& _event);

	/// <summary>
	/// The main ImGui update loop.
	/// </summary>
	/// <param name="_delta">(sf::Time) : Time since last frame.</param>
	void update(sf::Time _delta);

	/// <summary>
	/// Renders the ImGui Dockspace onto the window.
	/// </summary>
	void render();

	/// <summary>
	/// Shuts down the ImGui Dockspace.
	/// </summary>
	void shutdown();
private:
	sf::RenderWindow* m_window;
	ImGuiIO* m_io;
};