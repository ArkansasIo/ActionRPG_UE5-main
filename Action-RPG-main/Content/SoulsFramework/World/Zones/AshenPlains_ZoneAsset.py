# Example World Zone DataAsset

import unreal

class WorldZoneDataAsset(unreal.DataAsset):
    def __init__(self, name, description, biome, difficulty):
        self.name = name
        self.description = description
        self.biome = biome
        self.difficulty = difficulty

# Example usage
zone = WorldZoneDataAsset(
    name="Ashen Plains",
    description="A scorched wasteland with ancient ruins.",
    biome="Desert",
    difficulty="Medium"
)
