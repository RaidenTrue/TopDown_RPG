// This Project is Copyrighted as property of Savvas Stones.

using UnrealBuildTool;
using System.Collections.Generic;

public class TDRPGEditorTarget : TargetRules
{
	public TDRPGEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "TDRPG" } );
	}
}
