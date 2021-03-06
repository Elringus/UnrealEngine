// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IMovieSceneTrackInstance.h"

class FTrackInstancePropertyBindings;
class UMovieSceneVisibilityTrack;

/**
 * Instance of a UMovieSceneVisibilityTrack
 *
 * Visibility track instance is a specialized bool track instance that handles visibility in game and in editor
 *
 */
class FMovieSceneVisibilityTrackInstance : public IMovieSceneTrackInstance
{
public:
	FMovieSceneVisibilityTrackInstance( UMovieSceneVisibilityTrack& InVisibilityTrack );

	/** IMovieSceneTrackInstance interface */
	virtual void SaveState (const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player) override;
	virtual void RestoreState (const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player) override;
	virtual void Update( float Position, float LastPosition, const TArray<UObject*>& RuntimeObjects, class IMovieScenePlayer& Player ) override;
	virtual void RefreshInstance( const TArray<UObject*>& RuntimeObjects, class IMovieScenePlayer& Player ) override;
	virtual void ClearInstance( IMovieScenePlayer& Player ) override {}

private:
	/** Visibility track that is being instanced */
	UMovieSceneVisibilityTrack* VisibilityTrack;
	/** Runtime property bindings */
	TSharedPtr<class FTrackInstancePropertyBindings> PropertyBindings;
	/** Map from object to initial state */
	TMap< TWeakObjectPtr<UObject>, bool > InitHiddenInGameMap;
	TMap< TWeakObjectPtr<UObject>, bool > InitHiddenInEditorMap;
};
