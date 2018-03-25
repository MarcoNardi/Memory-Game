#pragma once

#include <memory>
#include <map>
#include "Textures.h"
#include <SFML/Graphics.hpp>


namespace Textures {

	class TextureHolder {
	private:
		std::map <Textures::ID,
			std::unique_ptr<sf::Texture>> TextureMap;
	public:
		void load(Textures::ID id, const std::string& filename);
		sf::Texture& get(Textures::ID id);
		const sf::Texture& get(Textures::ID id) const ;
	};
}