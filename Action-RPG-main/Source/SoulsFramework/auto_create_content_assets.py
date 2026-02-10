import unreal

def create_data_assets():
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    # Weapon DataAsset
    weapon_folder = "/Game/SoulsFramework/Data/DA_Weapons"
    unreal.EditorAssetLibrary.make_directory(weapon_folder)
    # Example: Create a base weapon asset
    weapon_factory = unreal.DataAssetFactory()
    asset_tools.create_asset("DA_Weapon_Sample", weapon_folder, unreal.UDA_Weapon, weapon_factory)

    # Attack DataTable
    attack_folder = "/Game/SoulsFramework/Data/DT_Attacks"
    unreal.EditorAssetLibrary.make_directory(attack_folder)
    dt_factory = unreal.DataTableFactory()
    asset_tools.create_asset("DT_Attacks", attack_folder, unreal.DataTable, dt_factory)

    # Stats DataTable
    stats_folder = "/Game/SoulsFramework/Data/DT_Stats"
    unreal.EditorAssetLibrary.make_directory(stats_folder)
    stats_factory = unreal.DataTableFactory()
    asset_tools.create_asset("DT_Stats", stats_folder, unreal.DataTable, stats_factory)

    # Damage DataTable
    damage_folder = "/Game/SoulsFramework/Data/DT_Damage"
    unreal.EditorAssetLibrary.make_directory(damage_folder)
    damage_factory = unreal.DataTableFactory()
    asset_tools.create_asset("DT_Damage", damage_folder, unreal.DataTable, damage_factory)

    # AI DataTable
    ai_folder = "/Game/SoulsFramework/Data/DT_AI"
    unreal.EditorAssetLibrary.make_directory(ai_folder)
    ai_factory = unreal.DataTableFactory()
    asset_tools.create_asset("DT_AI", ai_folder, unreal.DataTable, ai_factory)

if __name__ == "__main__":
    create_data_assets()
