// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SequencerPrivatePCH.h"
#include "ISettingsModule.h"
#include "ModuleManager.h"
#include "Sequencer.h"
#include "Toolkits/ToolkitManager.h"
#include "SequencerCommands.h"
#include "SequencerEdMode.h"
#include "SequencerObjectChangeListener.h"
#include "SequencerDetailKeyframeHandler.h"


// We disable the deprecation warnings here because otherwise it'll complain about us
// implementing RegisterTrackEditor and UnRegisterTrackEditor.  We know
// that, but we only want it to complain if *others* implement or call these functions.
//
// These macros should be removed when those functions are removed.
PRAGMA_DISABLE_DEPRECATION_WARNINGS

#define LOCTEXT_NAMESPACE "SequencerEditor"


/**
 * SequencerModule implementation (private)
 */
class FSequencerModule
	: public ISequencerModule
{
public:

	// ISequencerModule interface

	virtual TSharedRef<ISequencer> CreateSequencer(const FSequencerInitParams& InitParams) override
	{
		TSharedRef<FSequencer> Sequencer = MakeShareable(new FSequencer);
		TSharedRef<ISequencerObjectChangeListener> ObjectChangeListener = MakeShareable(new FSequencerObjectChangeListener(Sequencer, InitParams.bEditWithinLevelEditor));
		TSharedRef<IDetailKeyframeHandler> KeyframeHandler = MakeShareable( new FSequencerDetailKeyframeHandler( Sequencer ));

		Sequencer->InitSequencer(InitParams, ObjectChangeListener, KeyframeHandler, TrackEditorDelegates);

		return Sequencer;
	}
	
	virtual FDelegateHandle RegisterTrackEditor_Handle( FOnCreateTrackEditor InOnCreateTrackEditor ) override
	{
		TrackEditorDelegates.Add( InOnCreateTrackEditor );
		return TrackEditorDelegates.Last().GetHandle();
	}

	virtual void UnRegisterTrackEditor_Handle( FDelegateHandle InHandle ) override
	{
		TrackEditorDelegates.RemoveAll( [=](const FOnCreateTrackEditor& Delegate){ return Delegate.GetHandle() == InHandle; } );
	}

	virtual void StartupModule() override
	{
		if (GIsEditor)
		{
			FSequencerCommands::Register();

			FEditorModeRegistry::Get().RegisterMode<FSequencerEdMode>(
				FSequencerEdMode::EM_SequencerMode,
				NSLOCTEXT("Sequencer", "SequencerEditMode", "Sequencer Mode"),
				FSlateIcon(),
				false);
		}

		MenuExtensibilityManager = MakeShareable( new FExtensibilityManager );
		ToolBarExtensibilityManager = MakeShareable( new FExtensibilityManager );

		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->RegisterSettings("Project", "Editor", "Sequencer",
				LOCTEXT("RuntimeSettingsName", "Sequencer"),
				LOCTEXT("RuntimeSettingsDescription", "Configure the Sequencer plugin"),
				GetMutableDefault<USequencerProjectSettings>());
		}
	}

	virtual void ShutdownModule() override
	{
		if (GIsEditor)
		{
			FSequencerCommands::Unregister();

			FEditorModeRegistry::Get().UnregisterMode(FSequencerEdMode::EM_SequencerMode);
		}

		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Project", "Editor", "Sequencer");
		}
	}

	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() const override { return MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() const override { return ToolBarExtensibilityManager; }

private:

	/** List of auto-key handler delegates sequencers will execute when they are created */
	TArray< FOnCreateTrackEditor > TrackEditorDelegates;

	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;
};


PRAGMA_ENABLE_DEPRECATION_WARNINGS

IMPLEMENT_MODULE(FSequencerModule, Sequencer);

#undef LOCTEXT_NAMESPACE