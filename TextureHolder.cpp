#include "TextureHolder.h"

namespace Textures {

	void TextureHolder::load(Textures::ID id, const std::string & filename)
	{
		std::unique_ptr<sf::Texture> texture(new sf::Texture());
		if (!texture->loadFromFile("Resources/"+filename)) {
			texture->loadFromFile("Resources/missing.png");
		}
		TextureMap.insert(std::make_pair(id, std::move(texture)));
		
	}

	sf::Texture & TextureHolder::get(Textures::ID id)
	{
		auto trovato = TextureMap.find(id);
		return *trovato->second;
	}

	const sf::Texture & TextureHolder::get(Textures::ID id) const
	{
		auto trovato = TextureMap.find(id);
		return *trovato->second;
	}

}
