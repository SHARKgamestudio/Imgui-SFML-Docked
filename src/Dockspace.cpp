#include "Dockspace.h"

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "imgui.h"
#include "imgui-SFML.h"

#pragma endregion

Dockspace::Dockspace(sf::RenderWindow& _window) {
	bool success = ImGui::SFML::Init(_window);

	m_window = &_window;
	m_io = &ImGui::GetIO();

	m_io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	m_io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
}

void Dockspace::event(const sf::Event& _event) {
	ImGui::SFML::ProcessEvent(*m_window, _event);
}

void Dockspace::update(sf::Time _delta) {
	ImGui::SFML::Update(*m_window, _delta);
	ImGui::DockSpaceOverViewport();
}

void Dockspace::render() {
	ImGui::SFML::Render(*m_window);
	if (m_io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}

void Dockspace::shutdown() {
	ImGui::SFML::Shutdown();
}