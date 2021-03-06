// Copyright 2017 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GEOFENCE_H
#define GEOFENCE_H

namespace Esri
{
namespace ArcGISRuntime
{
class Map;
class MapQuickView;
class Graphic;
}
}

#include <QQuickItem>

class GeoFence : public QQuickItem
{
  Q_OBJECT

public:
  explicit GeoFence(QQuickItem* parent = nullptr);
  ~GeoFence() = default;

  void componentComplete() Q_DECL_OVERRIDE;
  static void init();

signals:
  void sendAlert(const QString& message);

private:
  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
  Esri::ArcGISRuntime::Graphic* m_graphic = nullptr;
  bool m_within = false;
  bool m_previouslyWithin = false;
};

#endif // GEOFENCE_H
