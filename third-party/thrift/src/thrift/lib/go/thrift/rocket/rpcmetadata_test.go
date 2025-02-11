/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package rocket

import (
	"testing"

	"thrift/lib/go/thrift"

	"github.com/stretchr/testify/require"
)

func TestRequestRPCMetadata(t *testing.T) {
	want := &RequestRPCMetadata{
		Name:    "test123",
		TypeID:  thrift.CALL,
		ProtoID: thrift.ProtocolIDCompact,
		Zstd:    true,
	}
	data, err := SerializeRequestRPCMetadata(want)
	require.NoError(t, err)
	got, err := DeserializeRequestRPCMetadata(data)
	require.NoError(t, err)
	require.Equal(t, want, got)
}
