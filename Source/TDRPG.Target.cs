// This Project is Copyrighted as property of Savvas Stones.

using UnrealBuildTool;
using System.Collections.Generic;

public class TDRPGTarget : TargetRules
{
	public TDRPGTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "TDRPG" } );
	}
}
